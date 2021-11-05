# Ratio.h

This is a ratio library implementation on arduino
    
## Documentation

Ratio : 

    ```
    typedef Ratio<value_1, value_2> R - create ratio R with value_1 as the numeator and value_2 as denumerator 
    typedef ratio_add<Ratio_1, Ratio_2> result - adding Ratio_1 and Ratio_2, 
    typedef ratio_subtract<Ratio_1, Ratio_2> result - subtracting Ratio_1 dan Ratio_2
    typedef ratio_multiply<Ratio_1, Ratio_2> result - multiplying Ratio_1 dan Ratio_2
    typedef ratio_divide<Ratio_1, Ratio_2> result - dividing Ratio_1 dan Ratio_2
    
        * result::num - return the result numerator
        * result::den - return the result denumerator
        * result::desc - return the decimal value of the ratio
    
    ratio_equal<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is equal to Ratio_2 decimal value
    ratio_not_equal<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is not equal to Ratio_2 decimal value
    ratio_less<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is less to Ratio_2 decimal value
    ratio_less_equal<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is less or equal to Ratio_2 decimal value
    ratio_greater<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is greater to Ratio_2 decimal value
    ratio_greater_equal<Ratio_1, Ratio_2>() - return true if Ratio_1 decimal value is greater or equal to Ratio_2 decimal value
    ```
    
## Examples
Here are some example for the Ratio libary :

  ```
  typedef Ratio<1,3> _R1;
  typedef Ratio<2,6> _R2;
  
  typedef ratio_add<_R1, _R2> add;
  typedef ratio_subtract<_R1, _R2> subtract;
  typedef ratio_multiply<_R1, _R2> multiply;
  typedef ratio_divide<_R1, _R2> divide;
  
  Serial.println(add::num) // Print the numerator from the ratio addition result
  Serial.println(multiply::den) // print the denumerator from the ratio multiplication result
  Serial.println(divide::desc) // print the decimal value from the ratio division result
  
  Serial.println(ratio_equal<_R1,_R2>()) // return true
  Serial.println(ratio_not_equal<_R1,_R2>()) // return false
  Serial.println(ratio_less<_R1,_R2>()) // return false
  Serial.println(ratio_less_equal<_R1,_R2>()) return true
  Serial.println(ratio_greater<_R1,_R2>()) return false
  Serial.println(ratio_greater_equal<_R1,_R2>()) return true
     
  ```

