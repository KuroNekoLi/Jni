#include <jni.h>
#include <string>
#include <android/log.h>


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cmake_MainActivity_add( JNIEnv* env, jobject thiz, jint a, jint b )
{
    return a+b;
}
#include <jni.h>
#include <string>
#include "Person.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmake_MainActivity_getPersonFullName(JNIEnv *env, jobject /* this */) {
    Person person("John", "Doe");
    std::string fullName = person.getFullName();
    return env->NewStringUTF(fullName.c_str());
}
#include<cstdio>
#include<cstdlib>
#include <complex.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_cmake_MainActivity_exChangeNumber( JNIEnv* env, jobject thiz, jintArray numbers )
{
    // Get the pointer to the array
    jint* numbers_ptr = env->GetIntArrayElements(numbers, nullptr);

    // Perform the swap
    int temp = numbers_ptr[0];
    numbers_ptr[0] = numbers_ptr[1];
    numbers_ptr[1] = temp;

    // Release the pointer
    env->ReleaseIntArrayElements(numbers, numbers_ptr, 0);
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cmake_MainActivity_callJavaMethodReturn( JNIEnv* env, jobject thiz, jint input )
{
    // 通过调用env->GetObjectClass()函数获取Java对象的类引用，参数“instance”表示MainActivity的实例。
    jclass clazz = env->GetObjectClass(thiz);

    // 通过调用env->GetMethodID()函数获取Java方法的ID，这里我们需要提供类引用、方法名和方法签名。
    // 方法签名是一个字符串，表示方法的参数类型和返回值类型。这里的“(I)I”表示方法接收一个整数参数并返回一个整数值。
    jmethodID methodID = env->GetMethodID(clazz, "multipleInJava", "(I)I");

    // 使用env->CallIntMethod()函数调用Java方法，这里我们需要提供Java对象实例、方法ID和输入参数。
    // 该函数将调用Java方法并返回结果。
    jint result = env->CallIntMethod(thiz, methodID, input);

    // 返回从Java方法获得的结果。
    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_cmake_MainActivity_checkCarSpeedNative(JNIEnv *env, jobject thiz, jobject carObject) {
    // 获取Car类
    jclass carClass = env->GetObjectClass(carObject);

    // 获取getSpeed方法的ID
    jmethodID getSpeedMethodId = env->GetMethodID(carClass, "getSpeed", "()I");

    // 调用getSpeed方法
    jint speed = env->CallIntMethod(carObject, getSpeedMethodId);

    // 在此处处理或使用从Java对象获取的速度值
//    if (speed > 120) {
//        // 如果速度大于120，打印出一条警告信息
//        __android_log_print(ANDROID_LOG_WARN, "LinLi", "Warning: The car is speeding! Current speed: %d", speed);
//    } else {
//        __android_log_print(ANDROID_LOG_INFO, "LinLi", "The car is driving at a safe speed: %d", speed);
//    }

    // 获取MainActivity类
    jclass mainActivityClass = env->GetObjectClass(thiz);
    // 获取logCarSpeed方法的ID
    jmethodID logCarSpeedMethodId = env->GetMethodID(mainActivityClass, "logCarSpeed", "(ZI)V");

    // 判断速度是否超过120
    jboolean isSpeeding = speed > 120;

    // 调用logCarSpeed方法
    env->CallVoidMethod(thiz, logCarSpeedMethodId, isSpeeding, speed);
}


