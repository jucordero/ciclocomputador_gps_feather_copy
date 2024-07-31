#define bici_width 120
#define bici_height 77
static const unsigned char bici_bits[] = PROGMEM {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f, 0x00, 0x00, 0xe0, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x7f, 0x00, 0x00,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff,
   0x7f, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf8, 0xff, 0x7f, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x3f, 0x00, 0x00, 0x80, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0x00, 0x00,
   0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
   0x00, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x1f, 0x00, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0xff, 0xff, 0xff, 0x3f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0xff, 0xff,
   0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xff, 0xff, 0xff, 0x7f, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0xe0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x3f, 0x00, 0x00,
   0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
   0x03, 0x00, 0x00, 0xf8, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0xf8, 0xfd, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0xff, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0xfc, 0xf8, 0xff,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xe7, 0xff, 0x00, 0x00, 0x00,
   0x7c, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xfb,
   0x01, 0x00, 0x00, 0x3e, 0xfc, 0xff, 0xff, 0x07, 0x00, 0x00, 0xf8, 0xff,
   0xff, 0xff, 0xf9, 0x01, 0x00, 0x00, 0x3f, 0xfe, 0xff, 0xff, 0x1f, 0x00,
   0x00, 0xfe, 0x1f, 0xe0, 0xff, 0xf1, 0x03, 0x00, 0x80, 0x1f, 0xff, 0x07,
   0xf8, 0x7f, 0x00, 0x00, 0xff, 0x03, 0x00, 0xff, 0xe3, 0x03, 0x00, 0xc0,
   0xdf, 0xff, 0x03, 0xc0, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xfc, 0xe7,
   0x07, 0x00, 0xc0, 0xef, 0xff, 0x07, 0x00, 0xff, 0x00, 0xc0, 0x3f, 0x00,
   0x00, 0xfe, 0xcf, 0x0f, 0x00, 0xe0, 0xf7, 0xcf, 0x07, 0x00, 0xfc, 0x03,
   0xc0, 0x1f, 0x00, 0x00, 0xfe, 0xcf, 0x0f, 0x00, 0xe0, 0xf7, 0x83, 0x0f,
   0x00, 0xf8, 0x03, 0xe0, 0x07, 0x00, 0x00, 0xbf, 0x9f, 0x1f, 0x00, 0xf0,
   0xfb, 0x81, 0x0f, 0x00, 0xe0, 0x07, 0xf0, 0x07, 0x00, 0x00, 0x3f, 0x1f,
   0x1f, 0x00, 0xf8, 0xfb, 0x81, 0x0f, 0x00, 0xe0, 0x0f, 0xf0, 0x03, 0x00,
   0x80, 0x1f, 0x3f, 0x3f, 0x00, 0xf8, 0xfd, 0x80, 0x0f, 0x00, 0xc0, 0x0f,
   0xf8, 0x00, 0x00, 0x80, 0x0f, 0x7e, 0x7e, 0x00, 0xfc, 0x7e, 0x00, 0x1f,
   0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0xc0, 0x07, 0x7c, 0x7c, 0x00, 0x7c,
   0x3e, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0x7c, 0x00, 0x00, 0xe0, 0x07, 0xf8,
   0xfc, 0x00, 0x3e, 0x1f, 0x00, 0x3e, 0x00, 0x00, 0x3e, 0x7c, 0x00, 0x00,
   0xe0, 0x03, 0xf8, 0xf8, 0x00, 0x3e, 0x1f, 0x00, 0x3e, 0x00, 0x00, 0x3e,
   0x3e, 0x00, 0x00, 0xf0, 0x03, 0xf8, 0xf9, 0x01, 0xbf, 0x1f, 0x00, 0x3e,
   0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0xf0, 0x01, 0xf0, 0xf1, 0x81, 0x9f,
   0x0f, 0x00, 0x7c, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0xf8, 0x01, 0xf0,
   0xe3, 0x83, 0xcf, 0x0f, 0x00, 0x7c, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00,
   0xfc, 0x00, 0xf0, 0xe3, 0xff, 0xc7, 0x07, 0x00, 0xf8, 0x00, 0x00, 0x7c,
   0x1e, 0x00, 0x00, 0x7c, 0x00, 0xe0, 0xc3, 0xff, 0xc7, 0x07, 0x00, 0xf8,
   0x01, 0x00, 0x78, 0x1f, 0x00, 0x00, 0x7e, 0x00, 0xe0, 0xc3, 0xff, 0xc3,
   0x07, 0x00, 0xf0, 0x01, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x3e, 0x00, 0xe0,
   0xc3, 0xff, 0xc3, 0x07, 0x00, 0xf0, 0x01, 0x00, 0xf8, 0x1f, 0x00, 0x00,
   0x3f, 0x00, 0xe0, 0xe3, 0xff, 0xc7, 0x07, 0x00, 0xf0, 0x01, 0x00, 0xf8,
   0x1f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc7, 0x07, 0x00, 0xf0,
   0x03, 0x00, 0xf8, 0x1f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc7,
   0x07, 0x00, 0xe0, 0x01, 0x00, 0xf8, 0x1f, 0x00, 0xc0, 0xff, 0xff, 0xff,
   0xff, 0x81, 0xc7, 0x07, 0x00, 0x40, 0x00, 0x00, 0xf8, 0x1e, 0x00, 0x80,
   0xff, 0xff, 0xff, 0xff, 0x81, 0xc7, 0x07, 0x00, 0x00, 0x00, 0x00, 0x78,
   0x1e, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc7, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe3, 0xff, 0xc7,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xc1, 0xff, 0x83, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0x81, 0xff, 0x81, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x7c,
   0x7c, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0xff, 0x81, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x3e, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x3c, 0x00,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00,
   0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x1f,
   0xf0, 0x01, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
   0x00, 0x80, 0x0f, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,
   0xfc, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xe0, 0x07, 0x00, 0x00, 0x80, 0x1f,
   0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0xe0, 0x07, 0xe0, 0x0f, 0x00,
   0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00, 0x00, 0xf0, 0x07,
   0xc0, 0x3f, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00,
   0x00, 0xfc, 0x03, 0x80, 0x7f, 0x00, 0x00, 0xf8, 0x07, 0x00, 0x00, 0x00,
   0xe0, 0x1f, 0x00, 0x00, 0xfe, 0x01, 0x00, 0xff, 0x01, 0x00, 0xfe, 0x03,
   0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0x80, 0xff, 0x00, 0x00, 0xfe, 0x1f,
   0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xf8, 0x7f, 0x00,
   0x00, 0xf8, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
   0xff, 0x1f, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf8, 0xff, 0xff, 0x07, 0x00, 0x00, 0x80, 0xff, 0xff, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfe,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0x01, 0x00, 0x00 };

   #define gear_width 57
   #define gear_height 77
   static const unsigned char gear_bits[] = PROGMEM{
      0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xf0,
      0x03, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0xf8, 0x0f, 0x00, 0x00, 0x00,
      0x00, 0xf8, 0x0f, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0xfc,
      0x0f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00,
      0x00, 0xf8, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff,
      0x07, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00,
      0x00, 0xf8, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff,
      0x3f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00,
      0x3c, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff,
      0xff, 0x3f, 0x00, 0x00, 0xfe, 0xff, 0x0f, 0xf0, 0xff, 0x7f, 0x00, 0x00,
      0xfe, 0xff, 0x03, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x01, 0x80,
      0xff, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x7f, 0x00, 0x00,
      0xff, 0x7f, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0x00,
      0xfe, 0x1f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00,
      0xf0, 0x3f, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00,
      0xfc, 0x07, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00,
      0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00,
      0xfc, 0x07, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00,
      0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00,
      0xfe, 0x7f, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
      0xfe, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x80,
      0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0x03, 0xe0, 0xff, 0x7f, 0x00, 0x00,
      0xfe, 0xff, 0x0f, 0xf8, 0xff, 0x7f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff,
      0xff, 0x3f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3c, 0x00, 0x00,
      0x78, 0xfe, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff,
      0x1f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
      0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
      0x0f, 0x80, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x80, 0x03, 0x00,
      0x00, 0xf0, 0xff, 0xff, 0x1f, 0xc6, 0x03, 0x00, 0x00, 0xf0, 0x3f, 0xf8,
      0x1f, 0xff, 0x07, 0x00, 0x00, 0xf0, 0x1f, 0xf0, 0x1f, 0xff, 0x7f, 0x00,
      0x00, 0xf0, 0x0f, 0xe0, 0x0f, 0xfe, 0xff, 0x00, 0x00, 0xc0, 0x0f, 0xc0,
      0x03, 0x3f, 0x7f, 0x00, 0x00, 0x00, 0x06, 0x00, 0x80, 0x0f, 0x3c, 0x00,
      0x00, 0x00, 0xc0, 0x07, 0xe0, 0x07, 0x38, 0x00, 0x00, 0x00, 0xc0, 0x07,
      0xe0, 0x07, 0x78, 0x00, 0x00, 0x00, 0xc0, 0x07, 0xe0, 0x07, 0xf8, 0x01,
      0x00, 0x80, 0xe1, 0x0f, 0x87, 0x07, 0xf8, 0x01, 0x00, 0xc0, 0xff, 0xff,
      0x8f, 0x07, 0xf8, 0x01, 0x00, 0xe0, 0xff, 0xff, 0x8f, 0x0f, 0xfc, 0x00,
      0x00, 0xe0, 0xff, 0xff, 0x8f, 0x1f, 0x3f, 0x00, 0x00, 0xc0, 0xff, 0xff,
      0xc7, 0xff, 0x1f, 0x00, 0x00, 0x80, 0x7f, 0xfc, 0x87, 0xff, 0x1f, 0x00,
      0x00, 0xc0, 0x1f, 0xf0, 0x07, 0xf8, 0x3f, 0x00, 0x00, 0xc0, 0x0f, 0xe0,
      0x07, 0xf0, 0x18, 0x00, 0x00, 0xe0, 0x07, 0xc0, 0x0f, 0x70, 0x00, 0x00,
      0x00, 0xfc, 0x07, 0xc0, 0x7f, 0x60, 0x00, 0x00, 0x00, 0xfc, 0x07, 0x80,
      0x7f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0x80, 0x7f, 0x00, 0x00, 0x00,
      0x00, 0xfc, 0x07, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0xc0,
      0x7f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0xc0, 0x0f, 0x00, 0x00, 0x00,
      0x00, 0xc0, 0x0f, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0xf0,
      0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00,
      0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
      0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00,
      0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe1, 0x0f,
      0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07,
      0x00, 0x00, 0x00, 0x00 };
