/*
 * Copyright (c) 1997, 2002, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#include <string.h>

#include "net_util.h"
#include <nativehelper/JNIHelp.h>

#define NATIVE_METHOD(className, functionName, signature) \
{ #functionName, signature, (void*)(className ## _ ## functionName) }

/************************************************************************
 * InetAddress
 */

jclass ia_class;
jclass iac_class;
jfieldID ia_holderID;
jfieldID iac_addressID;
jfieldID iac_familyID;
jfieldID iac_hostNameID;
jfieldID iac_origHostNameID;

static void InetAddress_init(JNIEnv *env) {
    jclass c = (*env)->FindClass(env,"java/net/InetAddress");
    CHECK_NULL(c);
    ia_class = (*env)->NewGlobalRef(env, c);
    CHECK_NULL(ia_class);
    c = (*env)->FindClass(env,"java/net/InetAddress$InetAddressHolder");
    CHECK_NULL(c);
    iac_class = (*env)->NewGlobalRef(env, c);
    ia_holderID = (*env)->GetFieldID(env, ia_class, "holder", "Ljava/net/InetAddress$InetAddressHolder;");
    CHECK_NULL(ia_holderID);

    iac_addressID = (*env)->GetFieldID(env, iac_class, "address", "I");
    CHECK_NULL(iac_addressID);
    iac_familyID = (*env)->GetFieldID(env, iac_class, "family", "I");
    CHECK_NULL(iac_familyID);
    iac_hostNameID = (*env)->GetFieldID(env, iac_class, "hostName", "Ljava/lang/String;");
    CHECK_NULL(iac_hostNameID);
    iac_origHostNameID = (*env)->GetFieldID(env, iac_class, "originalHostName", "Ljava/lang/String;");
    CHECK_NULL(iac_origHostNameID);
}

void register_java_net_InetAddress(JNIEnv* env) {
  InetAddress_init(env);
}
