//
//  utilities.h
//  ReiKey
//
//  Created by Patrick Wardle on 12/24/18.
//  Copyright © 2018 Objective-See. All rights reserved.
//

#ifndef Utilities_h
#define Utilities_h

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

/* FUNCTIONS */

//disable std err
void disableSTDERR(void);

//init crash reporting
void initCrashReporting(void);

//get path to (main) app
// login item is in app bundle, so parse up to get main app
NSString* getMainAppPath(void);

//get app's version
// ->extracted from Info.plist
NSString* getAppVersion(void);

//given a path to binary
// parse it back up to find app's bundle
NSBundle* findAppBundle(NSString* binaryPath);

//get process's path
NSString* getProcessPath(pid_t pid);

//path to login item
NSString* loginItemPath(void);

//get process name
// either via app bundle, or path
NSString* getProcessName(NSString* path);

//given a process path and user
// return array of all matching pids
NSMutableArray* getProcessIDs(NSString* processPath, int userID);

//given a pid, get its parent (ppid)
pid_t getParentID(int pid);

//enable/disable a menu
void toggleMenu(NSMenu* menu, BOOL shouldEnable);

//toggle login item
// either add (install) or remove (uninstall)
BOOL toggleLoginItem(NSURL* loginItem, int toggleFlag);

//add a login item
BOOL addLoginItem(NSURL* loginItem);

//remove a login item
BOOL removeLoginItem(NSURL* loginItem);

//start the (helper) login item
BOOL startLoginItem(void);

//get an icon for a process
// for apps, this will be app's icon, otherwise just a standard system one
NSImage* getIconForProcess(NSString* path);

//check if a kext is loaded
BOOL kextIsLoaded(NSString* kext);

//wait until kext is loaded
void wait4kext(NSString* kext);

//wait until a window is non nil
// then make it modal
void makeModal(NSWindowController* windowController);

//find a process by name
pid_t findProcess(NSString* processName);

//hash a file (sha256)
NSMutableString* hashFile(NSString* filePath);

//convert IP addr to (ns)string
NSString* convertIPAddr(unsigned char* ipAddr, __uint8_t socketFamily);

//convert socket numeric address to (ns)string
NSString* convertSocketAddr(struct sockaddr* socket);

//check if an instance of an app is already running
BOOL isAppRunning(NSString* bundleID, BOOL shouldActivate);

//exec a process with args
// if 'shouldWait' is set, wait and return stdout/in and termination status
NSMutableDictionary* execTask(NSString* binaryPath, NSArray* arguments, BOOL shouldWait, BOOL grabOutput);

//extract a DNS name
NSMutableString* extractDNSName(unsigned char* start, unsigned char* chunk, unsigned char* end);

//loads a framework
// note: assumes is in 'Framework' dir
NSBundle* loadFramework(NSString* name);

//restart
void restart(void);

//bring an app to foreground
// based on: https://stackoverflow.com/questions/7596643/when-calling-transformprocesstype-the-app-menu-doesnt-show-up
void foregroundApp(void);

//send an app to the background
void backgroundApp(void);

//transform app state
OSStatus transformApp(ProcessApplicationTransformState newState);

//check if (full) dark mode
// meaning, Mojave+ and dark mode enabled
BOOL isDarkMode(void);

//prettify JSON
NSString* prettifyJSON(NSString* output);

#endif
