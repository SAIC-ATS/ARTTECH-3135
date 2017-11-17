//
//  Emonalyzer.h
//  Blobism
//
//  Created by George Still on 11/16/17.
//

#import <Cocoa/Cocoa.h>
#import <Affdex/Affdex.h>

@interface ViewController : NSViewController <AFDXDetectorDelegate>

@property (strong) AFDXDetector *detector;
@property (strong) IBOutlet NSImageView *imageView;
@property (strong) IBOutlet NSTextField *textField;

@end
