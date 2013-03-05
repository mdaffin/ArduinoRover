#ifndef Debug_h
#define Debug_h
#ifdef DEBUG
  #define debug_print(x)  Serial.println (x)
#else
  #define debug_print(x)
#endif
#endif //Debug_h