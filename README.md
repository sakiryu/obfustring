# obfustring
A simple compile-time string obfuscation using xor

## usage
```
  #include "obfustring.hpp"
    
  int main()
  {
      auto a = obf("String A");
      auto b = obf("String B");
      auto c = obf("String C");
  }
```
