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
Generic implementation of the iOSStatusBar extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */

/**
 * @page EDKExtensionIOSStatusBarSource iOS Status Bar Extension Source Code and Project Files
 *
 * iOSStatusBar.mkf (includes this extension as a subproject):
 * @include iOSStatusBar.mkf
 *
 * Internal header (source/h/iOSStatusBar_internal.h):
 * @include ../h/iOSStatusBar_internal.h
 *
 * Generic source (source/generic/iOSStatusBarApp.cpp):
 * @include iOSStatusBar.cpp
 *
 * iOS source (source/iphone/iOSStatusBar_platform.mm):
 * @include ../iphone/iOSStatusBar_platform.mm
 *
 * Header for native module (incoming/MTStatusBarOverlay.h):
 * @include ../../incoming/MTStatusBarOverlay.h
 */

#include "iOSStatusBar_internal.h"
s3eResult iOSStatusBarInit()
{
    //Add any generic initialisation code here
    return iOSStatusBarInit_platform();
}

void iOSStatusBarTerminate()
{
    //Add any generic termination code here
    iOSStatusBarTerminate_platform();
}

void CreateMTStatusBar(s3eMTStatusAnimation animation, s3eMTDetailViewMode detailViewMode)
{
    CreateMTStatusBar_platform(animation, detailViewMode);
}

void PostMessage(s3eMTMessageType messageType, const char* message, int duration)
{
    PostMessage_platform(messageType, message, duration);
}
