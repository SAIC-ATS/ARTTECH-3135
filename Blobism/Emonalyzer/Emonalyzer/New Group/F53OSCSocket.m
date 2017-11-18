//
//  F53OSCSocket.m
//
//  Created by Christopher Ashworth on 1/28/13.
//
//  Copyright (c) 2013 Figure 53 LLC, http://figure53.com
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import "F53OSCSocket.h"
#import "F53OSCPacket.h"

#define TIMEOUT         3

#define END             0300    /* indicates end of packet */
#define ESC             0333    /* indicates byte stuffing */
#define ESC_END         0334    /* ESC ESC_END means END data byte */
#define ESC_ESC         0335    /* ESC ESC_ESC means ESC data byte */


@implementation F53OSCSocket

+ (F53OSCSocket *) socketWithTcpSocket:(GCDAsyncSocket *)socket
{
    return [[F53OSCSocket alloc] initWithTcpSocket:socket];
}

+ (F53OSCSocket *) socketWithUdpSocket:(GCDAsyncUdpSocket *)socket
{
    return [[F53OSCSocket alloc] initWithUdpSocket:socket];
}

- (id) initWithTcpSocket:(GCDAsyncSocket *)socket;
{
    self = [super init];
    if ( self )
    {
        _tcpSocket = socket;
        _udpSocket = nil;
        _host = @"localhost";
        _port = 0;
    }
    return self;
}

- (id) initWithUdpSocket:(GCDAsyncUdpSocket *)socket
{
    self = [super init];
    if ( self )
    {
        _tcpSocket = nil;
        _udpSocket = socket;
        _host = @"localhost";
        _port = 0;
    }
    return self;
}

- (void) dealloc
{
    [_tcpSocket setDelegate:nil];
    [_tcpSocket disconnect];
    //[_tcpSocket release];
    _tcpSocket = nil;
    
    [_udpSocket setDelegate:nil];
    //[_udpSocket release];
    _udpSocket = nil;
    
    //[_host release];
    _host = nil;
    
    //[super dealloc];
}

- (NSString *) description
{
    if ( self.isTcpSocket )
        return [NSString stringWithFormat:@"[TCP socket %@:%u isConnected = %i]", _host, _port, self.isConnected ];
    else
        return [NSString stringWithFormat:@"[UDP socket %@:%u]", _host, _port ];
}

- (GCDAsyncSocket *) tcpSocket
{
    return _tcpSocket;
}

- (GCDAsyncUdpSocket *) udpSocket
{
    return _udpSocket;
}

- (BOOL) isTcpSocket
{
    return ( _tcpSocket != nil );
}

- (BOOL) isUdpSocket
{
    return ( _udpSocket != nil );
}

@synthesize host = _host;

@synthesize port = _port;

- (BOOL) startListening
{
    if ( _tcpSocket )
        return [_tcpSocket acceptOnPort:_port error:nil];
    
    if ( _udpSocket )
    {
        if ( [_udpSocket bindToPort:_port error:nil] )
            return [_udpSocket beginReceiving:nil];
        else
            return NO;
    }
    
    return NO;
}

- (void) stopListening
{
    if ( _tcpSocket )
        [_tcpSocket disconnectAfterWriting];
    
    if ( _udpSocket )
        [_udpSocket close];
}

- (BOOL) connect
{
    if ( _tcpSocket )
    {
        if ( _host && _port )
            return [_tcpSocket connectToHost:_host onPort:_port error:nil];
        else
            return NO;
    }
    
    if ( _udpSocket )
        return YES;
    
    return NO;
}

- (void) disconnect
{
    [_tcpSocket disconnect];
}

- (BOOL) isConnected
{
    if ( _tcpSocket )
        return [_tcpSocket isConnected];
    
    if ( _udpSocket )
        return YES;
    
    return NO;
}

- (void) sendPacket:(F53OSCPacket *)packet
{
    //NSLog( @"%@ sending packet: %@", self, packet );
    
    NSData *data = [packet packetData];
    
    //NSLog( @"%@ sending message with native length: %li", self, [data length] );

    if ( _tcpSocket )
    {
        // Outgoing OSC messages are framed using the double END SLIP protocol: http://www.rfc-editor.org/rfc/rfc1055.txt
        
        NSMutableData *slipData = [NSMutableData data];
        Byte esc_end[2] = {ESC, ESC_END};
        Byte esc_esc[2] = {ESC, ESC_ESC};
        Byte end[1] = {END};
        
        [slipData appendBytes:end length:1];
        NSUInteger length = [data length];
        const Byte *buffer = [data bytes];
        for ( NSUInteger index = 0; index < length; index++ )
        {
            if ( buffer[index] == END )
                [slipData appendBytes:esc_end length:2];
            else if ( buffer[index] == ESC )
                [slipData appendBytes:esc_esc length:2];
            else
                [slipData appendBytes:&(buffer[index]) length:1];
        }
        [slipData appendBytes:end length:1];
        
        [_tcpSocket writeData:slipData withTimeout:TIMEOUT tag:[slipData length]];
    }
    else if ( _udpSocket )
    {
        [_udpSocket sendData:data toHost:_host port:_port withTimeout:TIMEOUT tag:0];
        [_udpSocket closeAfterSending];
    }
}

@end
