//
// Created by sanyinchen on 19-11-23.
//

#include <jni.h>
#include <string>

#include <JavaScriptCore/JavaScriptCore.h>

std::string JSStringToStdString(JSStringRef jsString) {
    size_t maxBufferSize = JSStringGetMaximumUTF8CStringSize(jsString);
    char *utf8Buffer = new char[maxBufferSize];
    size_t bytesWritten = JSStringGetUTF8CString(jsString, utf8Buffer, maxBufferSize);
    std::string utf_string = std::string(utf8Buffer, bytesWritten - 1);
    delete[] utf8Buffer;
    return utf_string;
}

extern "C" JNIEXPORT jstring

JNICALL
Java_com_sanyinchen_jsc_Bridge_stringFromJNI(JNIEnv *env, jobject /* this */, jstring content) {

    JSContextGroupRef contextGroup = JSContextGroupCreate();
    JSGlobalContextRef globalContext = JSGlobalContextCreateInGroup(contextGroup, nullptr);
    const char *str;
    str = env->GetStringUTFChars(content, JNI_FALSE);

    JSStringRef statement = JSStringCreateWithUTF8CString(str);

    JSValueRef retValue = JSEvaluateScript(globalContext, statement, nullptr, nullptr, 1, nullptr);

    JSStringRef retString = JSValueToStringCopy(globalContext, retValue, nullptr);

    std::string hello = JSStringToStdString(retString);

    JSGlobalContextRelease(globalContext);
    JSContextGroupRelease(contextGroup);
    JSStringRelease(statement);
    JSStringRelease(retString);
    env->ReleaseStringUTFChars(content, str);

    return env->NewStringUTF(hello.c_str());
}