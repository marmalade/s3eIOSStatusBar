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
 * Internal header for the iOSStatusBar extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 *
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#ifndef IOSSTATUSBAR_H_INTERNAL
#define IOSSTATUSBAR_H_INTERNAL

#include "s3eTypes.h"
#include "iOSStatusBar.h"
#include "iOSStatusBar_autodefs.h"

/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult iOSStatusBarInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult iOSStatusBarInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void iOSStatusBarTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void iOSStatusBarTerminate_platform();
void CreateMTStatusBar_platform(s3eMTStatusAnimation animation, s3eMTDetailViewMode detailViewMode);

void PostMessage_platform(s3eMTMessageType messageType, const char* message, int duration);

#endif /* !IOSSTATUSBAR_INTERNAL_H */
