package com.example.cmake;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.cmake.databinding.ActivityMainBinding;

import java.util.List;

public class MainActivity extends AppCompatActivity
{

    // Used to load the 'cmake' library on application startup.
    static
    {
        System.loadLibrary( "cmake" );
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate( Bundle savedInstanceState )
    {
        super.onCreate( savedInstanceState );

        binding = ActivityMainBinding.inflate( getLayoutInflater() );
        setContentView( binding.getRoot() );

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText( stringFromJNI() );

        int result = add(3,5);
        Log.d( "LinLi", "result: "+result );
        Log.d( "LinLi", "PersonFullName: "+getPersonFullName() );
        int[] numbers = {5, 3};
        exChangeNumber(numbers);
        Log.d( "LinLi", "a: " + numbers[0] + " b: " + numbers[1] );

        int javaResult = callJavaMethodReturn( 10 );
        Log.d( "LinLi", "C++: callJavaMethodAndReturn: " + javaResult);

        Car myCar = new Car("Tesla", 130);
        checkCarSpeed(myCar);
    }

    class Car {
        private String brand;
        private int speed;

        public Car(String brand, int speed) {
            this.brand = brand;
            this.speed = speed;
        }

        public String getBrand() {
            return brand;
        }

        public int getSpeed() {
            return speed;
        }
    }


    /**
     * A native method that is implemented by the 'cmake' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int add(int a, int b);
    public native String getPersonFullName();
    public native void exChangeNumber(int[] numbers);
    public int multipleInJava(int input){
        int result =input*2;
        Log.d( "LinLi", "multipleInJava: "+result );
        return result;
    }
    public native int callJavaMethodReturn(int input);

    public void checkCarSpeed(Car car) {
        checkCarSpeedNative(car);
    }

    public native void checkCarSpeedNative(Car car);

    public void logCarSpeed(boolean isSpeeding, int speed) {
        if (isSpeeding) {
            Log.w("LinLi", "Warning: The car is speeding! Current speed: " + speed);
        } else {
            Log.i("LinLi", "The car is driving at a safe speed: " + speed);
        }
    }
}