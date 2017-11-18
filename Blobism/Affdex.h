//
//  Affdex.h
//  Affdex.framework
//
//  Created by Boisy Pitre on 7/11/13.
//  Copyright (c) 2013-2016 Affectiva, Inc. All rights reserved.
//

#undef SDK_VERSION
#define SDK_VERSION "3.2.0"

#import <TargetConditionals.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif
#import <AVFoundation/AVFoundation.h>

#define ALLOW_DEPRECATED 1

@protocol AFDXDetectorDelegate;

/**
 \mainpage
 Welcome to the Affdex SDK for iOS and macOS! With this SDK, your iOS and macOS apps will be able to detect faces and their facial expressions using the built-in camera, or via a file on your iOS device or Mac.

 <b>Hardware Requirements</b>
 <br>
 <ul>
 <li>iOS: Any iPad, iPhone, or iPod Touch running iOS 8 or newer.</li>
 <li>macOS: A Mac running macOS 10.11 El Capitan or newer.</li>
 </ul>

 <b>Development Requirements</b>
 <br>
 <ul>
 <li> Xcode 8.2.1 or higher</li>
 </ul>

 <b>Getting Started</b>
 <br>
 To get started, visit https://github.com/Affectiva and pull down the source for one of our demo apps. Ensure that the Code Signing settings for the various projects are configured correctly. For iOS, the identity is configured for "iPhone Developer" which should match your identity automatically.
 ￼
 If you have any questions, comments or suggestions, please email them to sdk@affectiva.com.

 Enjoy the SDK!
 */


/*****************************************/
/********** ORIENTATION METRICS **********/
/*****************************************/

/**
 \brief
 This class encapsulates all of the orientation metrics for the face.
 */
@interface AFDXOrientation : NSObject <NSCoding>

/**
 \brief
 yaw is the left/right head angle (yaw) for the face (-30 degrees to 30 degrees).
 */
@property (assign) CGFloat  yaw;

/**
 \brief
 pitch is the up/down head angle (pitch) for the face (-30 degrees to 30 degrees).
 */
@property (assign) CGFloat  pitch;

/**
 \brief
 roll is the roll of the head angle for the face (-60 degrees to 60 degrees).
 */
@property (assign) CGFloat  roll;

/**
 \brief
 interocularDistance is the distance between the eyes in pixels.
 */
@property (assign) CGFloat  interocularDistance;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end

/*****************************************/
/**********    FACE QUALITY     **********/
/*****************************************/

/**
 \brief
 This class encapsulates all of the face quality metrics for the face.
 */
@interface AFDXFaceQuality : NSObject <NSCoding>

/**
 \brief
 Indicates how well the face is lit for purposes of analysis. Value range is [0, 100].
 There are no hard boundaries, but the following ranges can be considered as general guidelines:
 0-10: too dark
 10-25: suboptimal
 25-75: well lit
 75-90: suboptimal
 90-100: too bright
 */

@property (assign) CGFloat brightness;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end

/*****************************************/
/********** APPEARANCE  METRICS **********/
/*****************************************/

/**
 \brief
 This class encapsulates all of the appearance metrics for the face.
 */
@interface AFDXAppearance : NSObject <NSCoding>

/**
 \brief
 Age defines age ranges
 */
typedef enum {
    AFDX_AGE_UNKNOWN = 0,
    AFDX_AGE_UNDER_18 = 1,
    AFDX_AGE_18_24 = 2,
    AFDX_AGE_25_34 = 3,
    AFDX_AGE_35_44 = 4,
    AFDX_AGE_45_54 = 5,
    AFDX_AGE_55_64 = 6,
    AFDX_AGE_65_PLUS = 7
} Age;

/**
 \brief
 Ethnicity defines ethnicities
 */
typedef enum {
    AFDX_ETHNICITY_UNKNOWN = 0,
    AFDX_ETHNICITY_CAUCASIAN = 1,
    AFDX_ETHNICITY_BLACK_AFRICAN = 2,
    AFDX_ETHNICITY_SOUTH_ASIAN = 3,
    AFDX_ETHNICITY_EAST_ASIAN = 4,
    AFDX_ETHNICITY_HISPANIC = 5
} Ethnicity;

/**
 \brief
 Gender defines the enumerations for unknown, male, and female genders.
 */
typedef enum {
    AFDX_GENDER_UNKNOWN = 0,
    AFDX_GENDER_MALE = 1,
    AFDX_GENDER_FEMALE = 2
} Gender;

/**
 \brief
 Glasses defines the enumerations for faces with and without glasses.
 */
typedef enum {
    AFDX_GLASSES_NO = 0,
    AFDX_GLASSES_YES = 1
} Glasses;

/**
 \brief
 age is the detection of age of the face.
 */
@property (assign) Age  age;

/**
 \brief
 ethnicity is the determination of the ethnicity of the face.
 */
@property (assign) Ethnicity  ethnicity;

/**
 \brief
 glasses is the determination of the glasses on the face.
 */
@property (assign) Glasses  glasses;

/**
 \brief
 gender is the determination of the gender of the face.
 */
@property (assign) Gender  gender;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end


/*****************************************/
/**********       EMOJIS        **********/
/*****************************************/

/**
 \brief
 This class encapsulates all of the emoji metrics for the face.
 */
@interface AFDXEmoji : NSObject <NSCoding>

/**
 \brief
 Emoji is a typedef of values representing the different emojis available
 */
typedef enum {
    AFDX_EMOJI_RELAXED = 9786,
    AFDX_EMOJI_SMILEY = 128515,
    AFDX_EMOJI_LAUGHING = 128518,
    AFDX_EMOJI_KISSING = 128535,
    AFDX_EMOJI_DISAPPOINTED = 128542,
    AFDX_EMOJI_RAGE = 128545,
    AFDX_EMOJI_SMIRK = 128527,
    AFDX_EMOJI_WINK = 128521,
    AFDX_EMOJI_STUCK_OUT_TONGUE_WINKING_EYE = 128540,
    AFDX_EMOJI_STUCK_OUT_TONGUE = 128539,
    AFDX_EMOJI_FLUSHED = 128563,
    AFDX_EMOJI_SCREAM = 128561,
    AFDX_EMOJI_NONE = 128528
} Emoji;

/**
 \brief
 dominantEmoji is the current dominant emoji for the face.
 */
@property (assign) Emoji  dominantEmoji;

/**
 \brief
 laughing is the ranking of laughing for the face (0 to 100).
 */
@property (assign) CGFloat  laughing;

/**
 \brief
 smiley is the ranking of smiley for the face (0 to 100).
 */
@property (assign) CGFloat  smiley;

/**
 \brief
 relaxed is the ranking of relaxed for the face (0 to 100).
 */
@property (assign) CGFloat  relaxed;

/**
 \brief
 wink is the ranking of wink for the face (0 to 100).
 */
@property (assign) CGFloat  wink;

/**
 \brief
 kissing is the ranking of kissing for the face (0 to 100).
 */
@property (assign) CGFloat  kissing;

/**
 \brief
 stuckOutTongueWinkingEye is the ranking of stuck out tongue and winking eye for the face (0 to 100).
 */
@property (assign) CGFloat  stuckOutTongueWinkingEye;

/**
 \brief
 stuckOutTongue is the ranking of stuck out tongue for the face (0 to 100).
 */
@property (assign) CGFloat  stuckOutTongue;

/**
 \brief
 flushed is the ranking of flush for the face (0 to 100).
 */
@property (assign) CGFloat  flushed;

/**
 \brief
 disappointed is the ranking of disappointment for the face (0 to 100).
 */
@property (assign) CGFloat  disappointed;

/**
 \brief
 rage is the ranking of rage for the face (0 to 100).
 */
@property (assign) CGFloat  rage;

/**
 \brief
 scream is the ranking of screaming for the face (0 to 100).
 */
@property (assign) CGFloat  scream;

/**
 \brief
 smirk is the ranking of smirk for the face (0 to 100).
 */
@property (assign) CGFloat  smirk;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end


/*****************************************/
/**********      EMOTIONS       **********/
/*****************************************/

/**
 \brief
 This class encapsulates data about emotions
 */
@interface AFDXEmotions : NSObject <NSCoding>

/**
 \brief
 anger is the ranking of anger for the face (0 to 100).
 */
@property (assign) CGFloat anger;

/**
 \brief
 contempt is the ranking of contempt for the face (0 to 100).
 */
@property (assign) CGFloat contempt;

/**
 \brief
 disgust is the ranking of disgust for the face (0 to 100).
 */
@property (assign) CGFloat disgust;

/**
 \brief
 engagement is the ranking of engagement for the face (0 to 100).
 */
@property (assign) CGFloat engagement;

/**
 \brief
 fear is the ranking of fear for the face (0 to 100).
 */
@property (assign) CGFloat fear;

/**
 \brief
 joy is the ranking of joy for the face (0 to 100).
 */
@property (assign) CGFloat joy;

/**
 \brief
 sadness is the ranking of sadness for the face (0 to 100).
 */
@property (assign) CGFloat sadness;

/**
 \brief
 surprise is the ranking of surprise for the face (0 to 100).
 */
@property (assign) CGFloat surprise;

/**
 \brief
 valence is the ranking of the valence for the face (-100 to 100).
 */
@property (assign) CGFloat  valence;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end


/*****************************************/
/**********     EXPRESSIONS     **********/
/*****************************************/

/**
 \brief
 This class encapsulates all of the expression metrics for the face.
 */
@interface AFDXExpressions : NSObject <NSCoding>

/**
 \brief
 attention is the ranking of the attention for the face (0 to 100).
 */
@property (assign) CGFloat attention;

/**
 \brief
 browFurrow is the ranking of the brow furrow for the face (0 to 100).
 */
@property (assign) CGFloat browFurrow;

/**
 \brief
 browRaise is the ranking of the brow raise for the face (0 to 100).
 */
@property (assign) CGFloat browRaise;

/**
 \brief
 cheekRaise is the ranking of the cheek raise for the face (0 to 100).
 */
@property (assign) CGFloat  cheekRaise;

/**
 \brief
 chinRaise is the ranking of the chin raise for the face (0 to 100).
 */
@property (assign) CGFloat  chinRaise;

/**
 \brief
 dimpler is the ranking of the dimpler for the face (0 to 100).
 */
@property (assign) CGFloat  dimpler;

/**
 \brief
 eyeClosure is the ranking of the eye closure for the face (0 to 100).
 */
@property (assign) CGFloat  eyeClosure;

/**
 \brief
 eyeWiden is the ranking of the eye widening for the face (0 to 100).
 */
@property (assign) CGFloat  eyeWiden;

/**
 \brief
 innerBrowRaise is the ranking of the inner brow raise for the face (0 to 100).
 */
@property (assign) CGFloat  innerBrowRaise;

/**
 \brief
 jawDrop is the ranking of the jaw drop for the face (0 to 100).
 */
@property (assign) CGFloat jawDrop;

/**
 \brief
 lidTighten is the ranking of the lid tightening for the face (0 to 100).
 */
@property (assign) CGFloat lidTighten;

/**
 \brief
 lipCornerDepressor is the ranking of the lip depression for the face (0 to 100).
 */
@property (assign) CGFloat lipCornerDepressor;

/**
 \brief
 lipPress is the ranking of the lip press for the face (0 to 100).
 */
@property (assign) CGFloat  lipPress;

/**
 \brief
 lipPucker is the ranking of the lip pucker for the face (0 to 100).
 */
@property (assign) CGFloat  lipPucker;

/**
 \brief
 lipStretch is the ranking of the lip stretch for the face (0 to 100).
 */
@property (assign) CGFloat  lipStretch;

/**
 \brief
 lipSuck is the ranking of the lip suck for the face (0 to 100).
 */
@property (assign) CGFloat  lipSuck;

/**
 \brief
 mouthOpen is the ranking of the mouth open for the face (0 to 100).
 */
@property (assign) CGFloat  mouthOpen;

/**
 \brief
 noseWrinkle is the ranking of the nose wrinkle for the face (0 to 100).
 */
@property (assign) CGFloat  noseWrinkle;

/**
 \brief
 smile is the ranking of the smile for the face (0 to 100).
 */
@property (assign) CGFloat smile;

/**
 \brief
 smirk is the ranking of the smirk for the face (0 to 100).
 */
@property (assign) CGFloat  smirk;

/**
 \brief
 upperLipRaise is the ranking of the upper lip raise for the face (0 to 100).
 */
@property (assign) CGFloat  upperLipRaise;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;

@end

/*****************************************/
/**********     FACE OBJECT     **********/
/*****************************************/

/**
 \brief
 AFDXFace encapsulates a face and its various properties.
 */
@interface AFDXFace : NSObject <NSCoding>

/**
 \brief
 faceId is a unique identifier for a face in a frame.
 */
@property (assign) NSUInteger faceId;

/**
 \brief
 orientation contains the orientation values for the face.
 */
@property (strong) AFDXOrientation *orientation;

/**
 \brief
 faceQuality contains the face quality metrics.
 */
@property (strong) AFDXFaceQuality *faceQuality;

/**
 \brief
 appearance contains the appearance values for the face.
 */
@property (strong) AFDXAppearance *appearance;

/**
 \brief
 emojis contains the emojis for the face.
 */
@property (strong) AFDXEmoji *emojis;

/**
 \brief
 emotions contains the emotions for the face.
 */
@property (strong) AFDXEmotions *emotions;

/**
 \brief
 expressions contains the expressions for the face.
 */
@property (strong) AFDXExpressions *expressions;

/**
 \brief
 faceBounds contains the bounding box of the face in the frame.
 */
@property (assign) CGRect faceBounds;

/**
 \brief
 facePoints contains an array of CGPoints representing points on the face.
 */
@property (strong) NSArray *facePoints;

/**
 \brief
 userInfo private user data that can be associated with this face.
 */
@property (strong) id userInfo;

/**
 \brief
 Returns an XML representation of the object
 */
- (NSString *)xmlDescription;

/**
 \brief
 Returns a JSON representation of the object
 */
- (NSString *)jsonDescription;


#if ALLOW_DEPRECATED
/****************************************/
/********** DEPRECATED in V2.1 **********/
/****************************************/
/**
 \brief
 This holds the anger score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat angerScore __attribute__((deprecated));

/**
 \brief
 This holds the contempt score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat contemptScore __attribute__((deprecated));

/**
 \brief
 This holds the disgust score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat disgustScore __attribute__((deprecated));

/**
 \brief
 This holds the expressiveness score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat expressivenessScore __attribute__((deprecated));

/**
 \brief
 This holds the fear score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat fearScore __attribute__((deprecated));

/**
 \brief
 This holds the joy score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat joyScore __attribute__((deprecated));

/**
 \brief
 This holds the sadness score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat sadnessScore __attribute__((deprecated));

/**
 \brief
 This holds the surprise score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat surpriseScore __attribute__((deprecated));

/**
 \brief
 This holds the valence score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  valenceScore __attribute__((deprecated));

/**
 \brief
 This holds the attention score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat attentionScore __attribute__((deprecated));

/**
 \brief
 This holds the brow furrow score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat browFurrowScore __attribute__((deprecated));

/**
 \brief
 This holds the brow raise score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat browRaiseScore __attribute__((deprecated));

/**
 \brief
 This holds the chin raise score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  chinRaiseScore __attribute__((deprecated));

/**
 \brief
 This holds the eye closure score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  eyeClosureScore __attribute__((deprecated));

/**
 \brief
 This holds the inner brow raise score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  innerBrowRaiseScore __attribute__((deprecated));

/**
 \brief
 This holds the lip corner depressor score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat lipCornerDepressorScore __attribute__((deprecated));

/**
 \brief
 This holds the lip press score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  lipPressScore __attribute__((deprecated));

/**
 \brief
 This holds the lip pucker score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  lipPuckerScore __attribute__((deprecated));

/**
 \brief
 This holds the lip suck returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  lipSuckScore __attribute__((deprecated));

/**
 \brief
 This holds the mouth open score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  mouthOpenScore __attribute__((deprecated));

/**
 \brief
 This holds the nose wrinkle score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  noseWrinkleScore __attribute__((deprecated));

/**
 \brief
 This holds the smile score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat smileScore __attribute__((deprecated));

/**
 \brief
 This holds the smirk score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  smirkScore __attribute__((deprecated));

/**
 \brief
 This holds the upper lip raise score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  upperLipRaiseScore __attribute__((deprecated));

/**
 \brief
 This holds the inter ocular distance score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  interOcularDistanceScore __attribute__((deprecated));

/**
 \brief
 This holds the head angle left/right score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  headAngleLeftRightScore __attribute__((deprecated));

/**
 \brief
 This holds the head angle roll score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  headAngleRollScore __attribute__((deprecated));

/**
 \brief
 This holds the head angle up/down score returned by the detector. DEPRECATED.
 */
@property (assign) CGFloat  headAngleUpDownScore __attribute__((deprecated));
#endif

@end

/**
 \brief
 FaceMode defines the face finding mode for the detector.
 */
typedef enum {
    LARGE_FACES = 0,
    SMALL_FACES = 1
} FaceDetectorMode;

/**
 \brief
 This class utilizes Affdex's facial expression detection capabilities by analyzing video frames and returning information about the faces in each frame.

 The AFDXDetector class analyzes successive video frames in order to measure the number and degree of facial expressions of the subjects.
 Depending upon the initialization method used, the video frames may come from either the built-in camera of the device, via a file on
 the device, or pushed to the engine through a method.
 */
@interface AFDXDetector : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>

/**
 \enum AFDXCameraType
 This enumeration is used to specify the camera to use during recording.
 */
typedef enum
{
    /// The front camera specifier
    AFDX_CAMERA_FRONT = 0,
    /// The back camera specifier
    AFDX_CAMERA_BACK  = 1
} AFDXCameraType;

/**
 \brief
 This contains the license provided by Affectiva. DEPRECATED.
 */
@property (nonatomic, strong) NSString *licenseString __attribute__((deprecated));

/**
 \brief
 This contains the path to the license file provided by Affectiva. DEPRECATED.
 */
@property (nonatomic, strong) NSString *licensePath __attribute__((deprecated));

/**
 \brief
 This property returns the state of the detector.
 */
@property (readonly) BOOL isRunning;

/**
 \brief
 The queue used to call the delegate's adopted AFDXDetectorDelegate methods.
 */
@property dispatch_queue_t delegateQueue;

/**
 \brief
 The maximum process rate to operate in [FPS]
 */
@property (nonatomic, assign) float maxProcessRate;

/**
 \brief
 userInfo user-defined optional data that is carried with the detector object and useful in blocks
 */
@property (strong) id          userInfo;

/**
 \brief
 delegate The object destined to receive messages of the AFDXDetectorDelegate protocol.
 */
@property (weak)   id          delegate;

/*****************************************/
/********** GETTERS and SETTERS **********/
/*****************************************/
/**
 \brief
 Turns ON or OFF the age classifier.
 */
@property (nonatomic, assign) BOOL age;

/**
 \brief
 Turns ON or OFF the ethnicity classifier.
 */
@property (nonatomic, assign) BOOL ethnicity;

/**
 \brief
 Turns ON or OFF the glasses classifier.
*/
@property (nonatomic, assign) BOOL glasses;

/**
 \brief
 Turns ON or OFF the gender classifier.
 */
@property (nonatomic, assign) BOOL gender;

/**
 \brief
 Turns ON or OFF the anger classifier.
 */
@property (nonatomic, assign) BOOL anger;

/**
 \brief
 Turns ON or OFF the contempt classifier.
 */
@property (nonatomic, assign) BOOL contempt;

/**
 \brief
 Turns ON or OFF the disgust classifier.
 */
@property (nonatomic, assign) BOOL disgust;

/**
 \brief
 Turns ON or OFF the engagement classifier.
 */
@property (nonatomic, assign) BOOL engagement;
#if ALLOW_DEPRECATED
/**
 \brief
 Turns ON or OFF the expressiveness classifier. DEPRECATED.
 */
@property (nonatomic, assign) BOOL expressiveness __attribute__((deprecated));
#endif

/**
 \brief
 Turns ON or OFF the fear classifier.
 */
@property (nonatomic, assign) BOOL fear;

/**
 \brief
 Turns ON or OFF the joy classifier.
 */
@property (nonatomic, assign) BOOL joy;

/**
 \brief
 Turns ON or OFF the sadness classifier.
 */
@property (nonatomic, assign) BOOL sadness;

/**
 \brief
 Turns ON or OFF the surprise classifier.
 */
@property (nonatomic, assign) BOOL surprise;

/**
 \brief
 Turns ON or OFF the valance classifier.
 */
@property (nonatomic, assign) BOOL valence;

/**
 \brief
 Turns ON or OFF the attention classifier.
 */

@property (nonatomic, assign) BOOL attention;

/**
 \brief
 Turns ON or OFF the brow furrow classifier.
 */
@property (nonatomic, assign) BOOL browFurrow;

/**
 \brief
 Turns ON or OFF the brow raise classifier.
 */
@property (nonatomic, assign) BOOL browRaise;

/**
 \brief
 Turns ON or OFF the cheek raise classifier.
 */
@property (nonatomic, assign) BOOL cheekRaise;

/**
 \brief
 Turns ON or OFF the chin raise classifier.
 */
@property (nonatomic, assign) BOOL chinRaise;

/**
 \brief
 Turns ON or OFF the dimpler classifier.
 */
@property (nonatomic, assign) BOOL dimpler;

/**
 \brief
 Turns ON or OFF the eye closure classifier.
 */
@property (nonatomic, assign) BOOL eyeClosure;

/**
 \brief
 Turns ON or OFF the eye widen classifier.
 */
@property (nonatomic, assign) BOOL eyeWiden;

/**
 \brief
 Turns ON or OFF the inner brow raise classifier.
 */
@property (nonatomic, assign) BOOL innerBrowRaise;

/**
 \brief
 Turns ON or OFF the jaw drop classifier.
 */
@property (nonatomic, assign) BOOL jawDrop;

/**
 \brief
 Turns ON or OFF the lid tighten classifier.
 */
@property (nonatomic, assign) BOOL lidTighten;

/**
 \brief
 Turns ON or OFF the lip corner depressor classifier.
 */
@property (nonatomic, assign) BOOL lipCornerDepressor;

/**
 \brief
 Turns ON or OFF the lip press classifier.
 */
@property (nonatomic, assign) BOOL lipPress;

/**
 \brief
 Turns ON or OFF the lip pucker classifier.
 */
@property (nonatomic, assign) BOOL lipPucker;

/**
 \brief
 Turns ON or OFF the lip stretch classifier.
 */
@property (nonatomic, assign) BOOL lipStretch;

/**
 \brief
 Turns ON or OFF the lip suck classifier.
 */
@property (nonatomic, assign) BOOL lipSuck;

/**
 \brief
 Turns ON or OFF the mouth open classifier.
 */
@property (nonatomic, assign) BOOL mouthOpen;

/**
 \brief
 Turns ON or OFF the nose wrinkle classifier.
 */
@property (nonatomic, assign) BOOL noseWrinkle;

/**
 \brief
 Turns ON or OFF the smile classifier.
 */
@property (nonatomic, assign) BOOL smile;

/**
 \brief
 Turns ON or OFF the smirk classifier.
 */
@property (nonatomic, assign) BOOL smirk;

/**
 \brief
 Turns ON or OFF the upper lip raise classifier.
 */
@property (nonatomic, assign) BOOL upperLipRaise;

#if ALLOW_DEPRECATED

/**
 \brief
 Turns ON or OFF the inter ocular distance classifier. DEPRECATED.
 */
@property (nonatomic, assign) BOOL interOcularDistance __attribute__((deprecated));

/**
 \brief
 Turns ON or OFF the head angle left/right classifier. DEPRECATED.
 */
@property (nonatomic, assign) BOOL headAngleLeftRight __attribute__((deprecated));

/**
 \brief
 Turns ON or OFF the head angle roll classifier. DEPRECATED.
 */
@property (nonatomic, assign) BOOL headAngleRoll __attribute__((deprecated));

/**
 \brief
 Turns ON or OFF the head angle up/down classifier. DEPRECATED.
 */
@property (nonatomic, assign) BOOL headAngleUpDown __attribute__((deprecated));
#endif

/**
 \brief
 Returns the Affdex SDK version.

 \result
 The version of the Affdex SDK as a string.
 */
+ (NSString *)version;

/**
 \brief
 Resets the processing state of the detector.
 */
- (void)reset;

/**
 \brief
 Turns on or off the emoji classifiers.
 \param
 value        TRUE = turn on the emoji classifiers; FALSE = turn off the emoji classifiers
 */
- (void)setDetectEmojis:(BOOL)value;

/**
 \brief
 Turns on or off all appearance classifiers at once.
 \param
 value        TRUE = turn on all appearance classifiers; FALSE = turn off all appearance classifiers
 */
- (void)setDetectAllAppearances:(BOOL)value;

/**
 \brief
 Turns on or off all emotion classifiers at once.
 \param
 value        TRUE = turn on all emotion classifiers; FALSE = turn off all emotion classifiers
 */
- (void)setDetectAllEmotions:(BOOL)value;

/**
 \brief
 Turns on or off all expression classifiers at once.
 \param
 value        TRUE = turn on all expression classifiers; FALSE = turn off all expression classifiers
 */
- (void)setDetectAllExpressions:(BOOL)value;

/**
 \brief
 Initializes the ADFXDetector for processing video from a capture device using LARGE_FACES mode.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from any attached capture device. The caller specifices the AVCaptureDevice that will be used to capture the frames.

 Note that the object "owns" the camera device and will not relinquish it until the object is deallocated.

 \param
 delegate     The object which will receive emotion messages.
 \param
 device       The AVCaptureDevice object that will be used.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.

 @result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
    usingCaptureDevice:(AVCaptureDevice *)device
          maximumFaces:(NSUInteger)maximumFaces __attribute__((deprecated));

/**
 \brief
 Initializes the ADFXDetector for processing video from a capture device.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from any attached capture device. The caller specifices the AVCaptureDevice that will be used to capture the frames.

 Note that the object "owns" the camera device and will not relinquish it until the object is deallocated.

 \param
 delegate     The object which will receive emotion messages.
 \param
 device       The AVCaptureDevice object that will be used.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.
 \param
 faceMode     The face detection mode (LARGE_FACES or SMALL_FACES)

 @result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
    usingCaptureDevice:(AVCaptureDevice *)device
          maximumFaces:(NSUInteger)maximumFaces
              faceMode:(FaceDetectorMode)faceMode;

#if TARGET_OS_OSX
/**
 \brief
 Initializes the ADFXDetector for processing video from a capture device.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from any attached capture device. The caller specifices the AVCaptureDevice that will be used to capture the frames.

 Note that the object "owns" the camera device and will not relinquish it until the object is deallocated.

 \param
 delegate     The object which will receive emotion messages.
 \param
 device       The AVCaptureDevice object that will be used.
 \param
 horizontalFlip Horizontally flip images before processing if enabled.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.
 \param
 faceMode     The face detection mode (LARGE_FACES or SMALL_FACES)

 @result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
    usingCaptureDevice:(AVCaptureDevice *)device
    withHorizontalFlip:(BOOL)horizontalFlip
          maximumFaces:(NSUInteger)maximumFaces
              faceMode:(FaceDetectorMode)faceMode;
#endif

/**
 \brief
 Initializes the ADFXDetector for processing video from a camera.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from the camera
 on the device. The caller specifices which camera (front or back) will be used to capture the frames.

 Note that the object "owns" the camera device and will not relinquish it until the object is deallocated.

 \param
 delegate     The object which will receive emotion messages.
 \param
 camera       An enumerated value indicating which camera (AFDX_CAMERA_FRONT or AFDX_CAMERA_BACK)
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.

 @result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
           usingCamera:(AFDXCameraType)camera
          maximumFaces:(NSUInteger)maximumFaces __attribute__((deprecated));

/**
 \brief
 Initializes the ADFXDetector for processing video from a camera.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from the camera
 on the device. The caller specifices which camera (front or back) will be used to capture the frames.

 Note that the object "owns" the camera device and will not relinquish it until the object is deallocated.

 \param
 delegate     The object which will receive emotion messages.
 \param
 camera       An enumerated value indicating which camera (AFDX_CAMERA_FRONT or AFDX_CAMERA_BACK)
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.
 \param
 faceMode     The face detection mode (LARGE_FACES or SMALL_FACES)

 @result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
           usingCamera:(AFDXCameraType)camera
          maximumFaces:(NSUInteger)maximumFaces
              faceMode:(FaceDetectorMode)faceMode __attribute__((deprecated));

/**
 \brief
 Initializes the ADFXDetector for processing video from a file.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from a file
 on the device. The caller specifices the name of the movie file that contains the video to be processed.

 \param
 delegate     The object which will receive emotion messages.
 \param
 path         The path to the file containing the video.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.

 \result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
             usingFile:(NSString *)path
          maximumFaces:(NSUInteger)maximumFaces;

/**
 \brief
 Initializes the ADFXDetector for processing video from a file.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames from a file
 on the device. The caller specifices the name of the movie file that contains the video to be processed.

 \param
 delegate     The object which will receive emotion messages.
 \param
 path         The path to the file containing the video.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.
 \param
 faceMode     The face detection mode (LARGE_FACES or SMALL_FACES)

 \result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
             usingFile:(NSString *)path
          maximumFaces:(NSUInteger)maximumFaces
              faceMode:(FaceDetectorMode)faceMode;

/**
 \brief
 Initializes the ADFXDetector for processing video frames pushed by the caller.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames pushed from the caller.

 \param
 delegate     The object which will receive emotion messages.
 \param
 discrete     If TRUE, then images passed to processImage: are expected to be unrelated.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.

 \result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
        discreteImages:(BOOL)discrete
          maximumFaces:(NSUInteger)maximumFaces;

/**
 \brief
 Initializes the ADFXDetector for processing video frames pushed by the caller.

 This method initializes the Affdex facial expression engine and prepares it to receive video frames pushed from the caller.

 \param
 delegate     The object which will receive emotion messages.
 \param
 discrete     If TRUE, then images passed to processImage: are expected to be unrelated.
 \param
 maximumFaces The maximum number of faces that will be detected by the detector.
 \param
 faceMode     The face detection mode (LARGE_FACES or SMALL_FACES)

 \result
 The newly created object.
 */
- (id)initWithDelegate:(id <AFDXDetectorDelegate>)delegate
        discreteImages:(BOOL)discrete
          maximumFaces:(NSUInteger)maximumFaces
              faceMode:(FaceDetectorMode)faceMode;

/**
 \brief
 Starts the AFDXDetector's detection process.

 When an AFDXDetector receives this message, it will begin processing frames from the built-in camera or file (assuming the related initialization methods were used), looking for faces.

 \result
 If nil, no error; otherwise an NSError object.
*/
- (NSError *)start;

/**
 \brief
 Stops the AFDXDetector's detection process.

 When an AFDXDetector receives this message, it will stop processing frames.

 \result
 If nil, no error; otherwise an NSError object.
 */
- (NSError *)stop;

/**
 \brief
 Enables the analytics engine.
 */
- (void)enableAnalytics;

/**
 \brief
 Enables the analytics engine.
 */
- (void)disableAnalytics;

/**
 \brief
 Asks the AFDXDetector to process the passed image as a discrete image.

 This method is used when the initWithDelegate:discreteImages:maximumFaces: method is used to create the AFDXDetector.
 Callers may pass frames to this method at any rate that is suitable for them.
 The detector expects subsequent frames to be unrelated to previous frames (e.g. a series of still photos).

 \param
 facePicture A reference to an image object to process.
 */
#if TARGET_OS_IPHONE
- (void)processImage:(UIImage *)facePicture;
#else
- (void)processImage:(NSImage *)facePicture;
#endif

/**
 \brief
 Asks the AFDXDetector to process the passed UIImage (iOS) or NSImage (OS X).

 This method is used when the initWithDelegate:discreteImages:maximumFaces: method is used to create the AFDXDetector.
 Callers may pass frames to this method at any rate that is suitable for them.
 The detector expects subsequent frames to be related to previous frames (e.g. a video stream).

 \param
 facePicture A reference to a image object to process.
 \param
 time        The time into the stream associated with the facePicture to process.
 */
#if TARGET_OS_IPHONE
- (void)processImage:(UIImage *)facePicture atTime:(NSTimeInterval)time;
#else
- (void)processImage:(NSImage *)facePicture atTime:(NSTimeInterval)time;
#endif

/**
 \brief
 Rotate a UIImage (iOS) or NSImage (OS X) by the specified number of degrees.

 This method is useful for rotating image objects.

 \param
 src          The source image to rotate.
 \param
 angleDegrees The angle (in degrees) to rotate the image.

 \result
 The rotated image is returned.
 */
#if TARGET_OS_IPHONE
+ (UIImage *)rotateUIImage:(const UIImage *)src degrees:(float)angleDegrees;
#else
+ (NSImage *)rotateNSImage:(const NSImage *)src degrees:(float)angleDegrees;
#endif

/**
 \brief
 A convenience method for drawing points and rectangles on an image

 This method can be used to draw points and rectangles associated with faces on an image, as well as additional images.

 \param
 points An array of CGPoints to draw
 \param
 rectangles An array of CGRects to draw
 \param
 images An array of images to draw
 \param
 radius The radius of the points to draw
 \param
 pointColor  The color to use when drawing points
 \param
 rectangleColor The color to use when drawing rectangles
 \param
 imageRects An array of image frames for the passed images
 \param
 image The image to draw on.

 \result
 A new image that contains the drawn elements
 */
#if TARGET_OS_IPHONE
+ (UIImage *)imageByDrawingPoints:(NSArray *)points
                    andRectangles:(NSArray *)rectangles
                        andImages:(NSArray *)images
                       withRadius:(float)radius
                  usingPointColor:(UIColor *)pointColor
              usingRectangleColor:(UIColor *)rectangleColor
                  usingImageRects:(NSArray *)imageRects
                          onImage:(UIImage *)image;
#else
+ (NSImage *)imageByDrawingPoints:(NSArray *)points
                    andRectangles:(NSArray *)rectangles
                        andImages:(NSArray *)images
                       withRadius:(float)radius
                  usingPointColor:(NSColor *)pointColor
              usingRectangleColor:(NSColor *)rectangleColor
                  usingImageRects:(NSArray *)imageRects
                          onImage:(NSImage *)image;
#endif


/**
 \brief
 A convenience method for drawing points and rectangles on an image

 This method can be used to draw points and rectangles associated with faces on an image.

 \param
 points An array of CGPoints to draw
 \param
 rectangles An array of CGRects to draw
 \param
 radius The radius of the points to draw
 \param
 pointColor  The color to use when drawing points
 \param
 rectangleColor The color to use when drawing rectangles
 \param
 image The image to draw on.

 \result
 A new image that contains the drawn elements
 */
#if TARGET_OS_IPHONE
+ (UIImage *)imageByDrawingPoints:(NSArray *)points
                    andRectangles:(NSArray *)rectangles
                       withRadius:(float)radius
                  usingPointColor:(UIColor *)pointColor
              usingRectangleColor:(UIColor *)rectangleColor
                          onImage:(UIImage *)image;
#else
+ (NSImage *)imageByDrawingPoints:(NSArray *)points
                    andRectangles:(NSArray *)rectangles
                       withRadius:(float)radius
                  usingPointColor:(NSColor *)pointColor
              usingRectangleColor:(NSColor *)rectangleColor
                          onImage:(NSImage *)image;
#endif
@end

/**
 \protocol        AFDXDetectorDelegate

 \brief
 This protocol provides methods that the AFDXDetector uses to communicate to users of the class.
 */
@protocol AFDXDetectorDelegate

/**
 \brief
 Indicates that the face detector has processed the video.

 When the face tracker completes processing of the last frame, this method is called.
 (Applies only to processing of video files).

 \param
 detector    A pointer to the AFDXDetector object.
 */
@optional
- (void)detectorDidFinishProcessing:(AFDXDetector *)detector;

/**
 \brief
 Indicates that the face detector has started tracking a face.

 When the face tracker detects a face, this method is called. The receiver should expect that tracking continues until
 a call to detectorDidStop: occurs.

 \param
 detector    A pointer to the AFDXDetector object.
 \param
 face        A pointer to the AFDXFace object which has entered the frame.
 */
@optional
- (void)detector:(AFDXDetector *)detector didStartDetectingFace:(AFDXFace *)face;

/**
 \brief
 Indicates that the face detector has stopped tracking a face.

 When the face tracker no longer detects a face, this method is called. The receiver should expect that there is no
 face tracking until a call to detectorDidStart: occurs.

 \param
 detector    A pointer to the AFDXDetector object.
 \param
 face        A pointer to the AFDXFace object which has exited the frame.
 */
@optional
- (void)detector:(AFDXDetector *)detector didStopDetectingFace:(AFDXFace *)face;

/**
 \brief
 Called for all frames captured. Contains information for facial expressions detected for a particular time.

 When an facial expression has been detected at a specific point in the video stream, this method will be called with an
 array of AFDXMetric objects. The number of objects passed equals to the number of facial expressions requested when
 the detector was initialized.

 A reference to the actual image that was analyzed is passed as well. This can be useful for displaying in a view
 or doing other relevant processing.

 The time into the stream that the facial expression occurred is also available.  This is a relative time composed indicating
 the number of seconds into the processing stream that the frame occurred.

 This method will also be called if captured frame did not result in the detection of any facial expressions. This may happen for when no face is detected. In this case the array of AFDXMetric objects will be nil.

 \param
 detector    A pointer to the AFDXDetector object.
 \param
 faces       A dictionary of AFDXFace objects, indexed by face Id, which represents the faces that were present. Nil if none were detected for a particular frame.
 \param
 image       A reference to the image which was analyzed.
 \param
 time        The time into the stream that the facial expression was expressed.
 */
@required
#if TARGET_OS_IPHONE
- (void)detector:(AFDXDetector *)detector hasResults:(NSMutableDictionary *)faces forImage:(UIImage *)image atTime:(NSTimeInterval)time;
#else
- (void)detector:(AFDXDetector *)detector hasResults:(NSMutableDictionary *)faces forImage:(NSImage *)image atTime:(NSTimeInterval)time;
#endif

@end


