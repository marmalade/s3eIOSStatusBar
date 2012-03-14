/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2011 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
/*
 * iphone-specific implementation of the iOSStatusBar extension.
 * Add any platform-specific functionality here.
 *
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */

#include "s3eTypes.h"
#include "s3eEdk.h"
#include "s3eEdk_iphone.h"
#include "IwDebug.h"

#import <UIKit/UIKit.h>

#include "iOSStatusBar_internal.h"
#include "MTStatusBarOverlay.h"



s3eResult iOSStatusBarInit_platform()
{

    //Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void iOSStatusBarTerminate_platform()
{
    //Add any platform-specific termination code here
}

void CreateMTStatusBar_platform_mt(s3eMTStatusAnimation animation, s3eMTDetailViewMode detailViewMode)
{
    [[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO]; 

    MTStatusBarOverlay *overlay = [MTStatusBarOverlay sharedInstance];
    overlay.animation = (MTStatusBarOverlayAnimation)animation;  
    overlay.detailViewMode = (MTDetailViewMode)detailViewMode;
}

void CreateMTStatusBar_platform(s3eMTStatusAnimation animation, s3eMTDetailViewMode detailViewMode)
{
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)CreateMTStatusBar_platform_mt, 2,
        animation, detailViewMode);
}

void PostMessage_platform(s3eMTMessageType messageType, const char* message, int duration)
{
    NSTimeInterval time_interval = 0.001 * (NSTimeInterval)duration;
    NSString* msg = [NSString stringWithUTF8String:message];
    MTStatusBarOverlay *overlay = [MTStatusBarOverlay sharedInstance];

    switch(messageType)
    {
    case s3eMTMessageTypeActivity:
        [overlay postMessage:msg duration:time_interval];
        break;
    case s3eMTMessageTypeFinish:
        [overlay postFinishMessage:msg duration:time_interval];
        break;
    case s3eMTMessageTypeError:
        [overlay postErrorMessage:msg duration:time_interval];
        break;
    }
}