#include <jni.h>
#include <string>
#include <iostream>

#include <android/log.h>

#define TAG "native-lib"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__);

using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_zyh_jnistudy_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_zyh_jnistudy_MainActivity_testAll(JNIEnv *env
                                           , jobject thiz
                                           , jboolean b
                                           , jbyte b1
                                           , jchar c,
                                           jshort s
                                           , jlong l
                                           , jfloat f
                                           , jdouble d) {

    //接收boolean类型值
    unsigned char c_boolean = b;
    LOGD("boolean -> %d",c_boolean)
    //接收byte类型值
    signed char c_byte = b1;
    LOGD("byte -> %d",c_byte)
    //接收char类型值
    unsigned short c_char = c;
    LOGD("char -> %d",c_char)
    //接收short类型值
    short c_short = s;
    LOGD("short -> %d",c_short)
    //接收long类型值
    long long c_long = l;
    LOGD("long -> %lld",c_long)
    //接收float类型值
    float c_float = f;
    LOGD("float -> %f",c_float)
    //接收double类型值
    double c_double = d;
    LOGD("double -> %f",c_double)
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zyh_jnistudy_MainActivity_testAll2(JNIEnv *env
                                            , jobject thiz
                                            , jintArray int_array
                                            , jobjectArray string_array
                                            , jstring string
                                            , jobject book,
                                            jobject book_list) {

    //解析int数组 引用类型前面也说了，没有直接对应的基本数据类型，被隐藏起来了
    jint *intArray = env->GetIntArrayElements(int_array,NULL);
    //拿到数组长度
    jsize intArraySize = env->GetArrayLength(int_array);
    for (int i = 0; i < intArraySize; ++i) {
        LOGD("int数组是 -> %d",intArray[i]);
    }
    //释放数组
    env->ReleaseIntArrayElements(int_array,intArray,0);

    //解析string数组，这里会发现类型是jobjectArray了，不是具体类型了
    //这里就不能按照前面的步骤来了，因为可以想一下，这个类型不固定，所以不存在jobject指针来指出数组
    //jobject *stringArray = env->GetObjectArrayElement(string_array,NULL);
    jsize stringArraySize = env->GetArrayLength(string_array);
    for (int i = 0; i < stringArraySize; ++i) {
        jobject jobject1 = env->GetObjectArrayElement(string_array,i);
        //强转
        jstring stringArrayData = static_cast<jstring>(jobject1);
        //把jstring转成C/C++类型
        const char *stringData = env->GetStringUTFChars(stringArrayData, NULL);
        LOGD("string数组值是 -> %s",stringArrayData)
        env->ReleaseStringUTFChars(stringArrayData,stringData);
    }

    //解析string
    jstring stringData = static_cast<jstring>(string);
    const char *string1 = env->GetStringUTFChars(stringData, NULL);
    LOGD("string数组值是 -> %s",string1)
    env->ReleaseStringUTFChars(stringData,string1);

    //解析自定义类


}