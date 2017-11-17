//
//  ViewController.m
//  Emonalyzer
//
//  Created by George Still on 11/16/17.
//  Copyright © 2017 George Still. All rights reserved.
//

#import "ViewController.h"

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
    if(faces == nil)
    {
        self.imageView.image = image;
    }
    else
    {
        NSArray *a = [faces allValues];
        if(a.count > 0){
//            AFDXFace *face = [a objectAtIndex:0];
//
//            NSNumber * joy = [NSNumber numberWithFloat:face.emotions.joy];
//            NSNumber * anger = [NSNumber numberWithFloat:face.emotions.anger];
//            NSNumber * surprise = [NSNumber numberWithFloat:face.emotions.surprise];
//            NSNumber * contempt = [NSNumber numberWithFloat:face.emotions.contempt];
//            NSNumber * sadness = [NSNumber numberWithFloat:face.emotions.sadness];
//            NSNumber * valence = [NSNumber numberWithFloat:face.emotions.valence];
//            NSNumber * engagement = [NSNumber numberWithFloat:face.emotions.engagement];
//            NSNumber * disgust = [NSNumber numberWithFloat:face.emotions.disgust];
//            NSNumber * fear = [NSNumber numberWithFloat:face.emotions.fear];
//
//            NSNumber * attention = [NSNumber numberWithFloat:face.expressions.attention];
//            NSNumber * browFurrow = [NSNumber numberWithFloat:face.expressions.browFurrow];
//            NSNumber * browRaise = [NSNumber numberWithFloat:face.expressions.browRaise];
//            NSNumber * cheekRaise = [NSNumber numberWithFloat:face.expressions.cheekRaise];
//            NSNumber * chinRaise = [NSNumber numberWithFloat:face.expressions.chinRaise];
//            NSNumber * dimpler = [NSNumber numberWithFloat:face.expressions.dimpler];
//            NSNumber * eyeClosure = [NSNumber numberWithFloat:face.expressions.eyeClosure];
//            NSNumber * eyeWiden = [NSNumber numberWithFloat:face.expressions.eyeWiden];
//            NSNumber * innerBrowRaise = [NSNumber numberWithFloat:face.expressions.innerBrowRaise];
//            NSNumber * jawDrop = [NSNumber numberWithFloat:face.expressions.jawDrop];
//            NSNumber * lidTighten = [NSNumber numberWithFloat:face.expressions.lidTighten];
//            NSNumber * lipSuck = [NSNumber numberWithFloat:face.expressions.lipSuck];
//            NSNumber * lipPress = [NSNumber numberWithFloat:face.expressions.lipPress];
//            NSNumber * lipPucker = [NSNumber numberWithFloat:face.expressions.lipPucker];
//            NSNumber * lipStretch = [NSNumber numberWithFloat:face.expressions.lipStretch];
//            NSNumber * lipCornerDepressor = [NSNumber numberWithFloat:face.expressions.lipCornerDepressor];
//            NSNumber * mouthOpen = [NSNumber numberWithFloat:face.expressions.mouthOpen];
//            NSNumber * noseWrinkle = [NSNumber numberWithFloat:face.expressions.noseWrinkle];
//            NSNumber * smile = [NSNumber numberWithFloat:face.expressions.smile];
//            NSNumber * smirk = [NSNumber numberWithFloat:face.expressions.smirk];
//            NSNumber * upperLipRaise = [NSNumber numberWithFloat:face.expressions.upperLipRaise];
//
//            NSArray *expressionsArray = [NSArray arrayWithObjects: attention, browFurrow, browRaise, cheekRaise,
//                                                    chinRaise, dimpler, eyeClosure, eyeClosure,
//                                                    eyeWiden, innerBrowRaise, jawDrop, lidTighten,
//                                                    lipSuck, lipPress, lipPucker, lipStretch,
//                                                    lipCornerDepressor, mouthOpen, noseWrinkle, smile,
//                                         smirk, upperLipRaise, nil
//                                                    ];
//
//            NSArray *emotionsArray = [NSArray arrayWithObjects: joy, anger, surprise, contempt, sadness, valence, engagement, disgust, fear];
//
//            for(NSNumber *exp in expressionsArray){
//                if([exp floatValue] > 90.0f){
//                    self.textField.stringValue = [NSString stringWithFormat:@"%@: %.1f", [exp description], [exp floatValue]];
//                }
//            }
//
//            for(NSNumber *emp in emotionsArray){
//                if([emp floatValue] > 90.0f){
//                    self.textField.stringValue = [NSString stringWithFormat:@"%s: %.1f", emp, [emp floatValue]];
//                }
//            }
            
        }
    }
}


@end
