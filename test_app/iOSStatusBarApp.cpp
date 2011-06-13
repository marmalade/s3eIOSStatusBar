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
 
/**
 * @page EDKExtensionIOSStatusBarTest iOS Status Bar Test Application
 *
 * The test application demonstrates how to include and use the iOS Status Bar
 * EDK extension example. It creates a status bar and sends a test message to
 * it when the user touches the screen.
 *
 * It uses the following functions:
 * - CreateMTStatusBar()
 * - PostMessage()
 *
 * MKB:
 * @include iOSStatusBarApp.mkb
 *
 * Source:
 * @include iOSStatusBarApp.cpp
 */
 
#include "iOSStatusBar.h"
#include "s3eDevice.h"
#include "s3ePointer.h"
#include "s3eSurface.h"
#include "s3eTimer.h"
#include "IwDebug.h"


S3E_MAIN_DECL int main()
{
    int screen_presses = 0;

    CreateMTStatusBar(s3eMTStatusBarOverlayAnimationFallDown, s3eMTDetailViewModeDetailText);
    PostMessage(s3eMTMessageTypeActivity, "Touch the screen to view status messages", 2000);

    while (!s3eDeviceCheckQuitRequest())
    {       
        s3eDeviceYield(0);
        s3ePointerUpdate();
        s3eDebugPrint(0,30,"Status bar test application", 0);
        s3eSurfaceShow();

        if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_PRESSED)
        {
            char str[128];
            sprintf(str, "Status bar test %d...", screen_presses++);
            PostMessage(s3eMTMessageTypeActivity, str, 1000);
        }
    }

    return 0;
}
