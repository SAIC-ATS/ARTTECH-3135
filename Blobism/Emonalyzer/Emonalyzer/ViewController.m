//
//  ViewController.m
//  Emonalyzer
//
//  Created by George Still on 11/16/17.
//  Copyright © 2017 George Still. All rights reserved.
//

#import "ViewController.h"

#define SENDHOST @"127.0.0.1"
#define SENDPORT 12001

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    
    NSArray<AVCaptureDevice *> *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    AVCaptureDevice *device = [devices objectAtIndex:0];
    
    //Probably need to change this once kinect is hooked up
    self.detector = [[AFDXDetector alloc] initWithDelegate:self usingCaptureDevice: device maximumFaces:1 faceMode:LARGE_FACES];
    
    [self.detector setDetectAllEmotions:YES];
    [self.detector setDetectAllExpressions:YES];
    self.detector.maxProcessRate = 5;
    [self.detector start];
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

- (void)detector:(AFDXDetector *)detector hasResults:(NSMutableDictionary *)faces forImage:(NSImage *)image atTime:(NSTimeInterval)time
{
    
    NSDictionary *userInfo = @{
                               NSLocalizedDescriptionKey: NSLocalizedString(@"Operation was unsuccessful.", nil),
                               NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"The operation timed out.", nil),
                               NSLocalizedRecoverySuggestionErrorKey: NSLocalizedString(@"Have you tried turning it off and on again?", nil)
                               };
    
    
    NSError *e = nil;
    
    if(faces == nil)
    {
        self.imageView.image = image;
    }
    else
    {
        NSArray *a = [faces allValues];
        if(a.count > 0){
            AFDXFace *face = [a objectAtIndex:0];
            
            if (!self.oscClient)
                self.oscClient = [[F53OSCClient alloc] init];
            
            NSString *faceJSON = [face jsonDescription];

            NSArray *facePoints = [face facePoints];
            
            NSMutableArray *facePointsNSNums;
            
            for(int i = 0; i< [facePoints count]; i++){
                facePointsNSNums[i] = [NSNumber numberWithFloat:[facePoints[i] floatValue]];
            }
            
            NSString *jsonString;
            
            if([facePoints count] > 0){
                NSData *jsonFacePointData = [NSJSONSerialization dataWithJSONObject: facePointsNSNums options:NSJSONWritingPrettyPrinted error:&e];
                
                jsonString = [[NSString alloc] initWithData:jsonFacePointData encoding:NSUTF8StringEncoding];
            }
            
            F53OSCMessage *emotionMessage = [F53OSCMessage messageWithAddressPattern:@"/Emonalyzer/emotions"
                                                                    arguments:@[faceJSON]];
            
            F53OSCMessage *facePointsMessage = [F53OSCMessage messageWithAddressPattern:@"/Emonalyzer/facePoints"
                                                                    arguments:@[jsonString]];
//
//            [self.oscClient sendPacket:emotionMessage toHost:SENDHOST onPort:SENDPORT];
            [self.oscClient sendPacket:facePointsMessage toHost:SENDHOST onPort:SENDPORT];


        }
    }
}

@end
