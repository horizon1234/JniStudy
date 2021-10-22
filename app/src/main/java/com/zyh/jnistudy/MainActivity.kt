package com.zyh.jnistudy

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.zyh.jnistudy.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()

        //调用
        testAll(true
            ,1
            ,'X'
            ,2
            ,3L
            ,3F
            ,"4".toDouble())
    }

    /**
     * A native method that is implemented by the 'jnistudy' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun testAll(b: Boolean
                         ,b1: Byte
                         ,c: Char
                         ,s: Short
                         ,l: Long
                         ,f: Float
                         ,d: Double)

    external fun testAll2(intArray: IntArray
                          ,stringArray: Array<String>
                          ,string: String
                          ,book: Book
                          ,bookList: ArrayList<Book>)


    companion object {
        // Used to load the 'jnistudy' library on application startup.
        init {
            System.loadLibrary("jnistudy")
        }
    }
}