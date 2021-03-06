/*
Blocked Out
    Copyright (C) 2015 James Downs
    james.j.downs@icloud.com
*/

#define COUNTRY 0
#define TEMPERATURE_1 1
#define TEMPERATURE_2 2
#define TEMPERATURE_3 3
#define TEMPERATURE_4 4
#define TEMPERATURE_5 5
#define CONDITIONS_1 6
#define CONDITIONS_2 7
#define CONDITIONS_3 8
#define CONDITIONS_4 9
#define HUMIDITY 10

#define BOX_X 63
#define BOX_Y 70

#define ANIM_DURATION 500
#define ANIM_DELAY 300
#define ANIM_DELAY_INFO 800
#define ANIM_DELAY_FORE 1000

static Window *s_main_window;
static Layer *s_background_layer, *s_info_layer, *s_date_1_layer, *s_date_2_layer, *s_ch_layer, *s_bluetooth_layer, *s_battery_layer;
static TextLayer *s_weather_label, *s_weather1_label, *s_weather2_label, *s_weather3_label, *s_weather4_label;
static TextLayer *s_day_label, *s_month_label, *s_date_label, *s_conditions_label, *s_humidity_label;

static Layer *s_hour1_parent, *s_hour2_parent, *s_minute1_parent, *s_minute2_parent;
static Layer *s_weather1_parent, *s_weather2_parent, *s_weather3_parent, *s_weather4_parent;

static BitmapLayer *s_hour1_layer, *s_hour2_layer, *s_minute1_layer, *s_minute2_layer;
static BitmapLayer *s_weather1_layer, *s_weather2_layer, *s_weather3_layer, *s_weather4_layer;

static GBitmap *s_hour1_bitmap, *s_hour2_bitmap, *s_minute1_bitmap, *s_minute2_bitmap; 
static GBitmap *s_weather1_bitmap, *s_weather2_bitmap, *s_weather3_bitmap, *s_weather4_bitmap;

static PropertyAnimation *s_info_animation, *s_date_1_animation, *s_date_2_animation, *s_shake_animation;
static PropertyAnimation *s_hour1_animation, *s_hour2_animation, *s_minute1_animation, *s_minute2_animation;
static PropertyAnimation *s_weather1_animation, *s_weather2_animation, *s_weather3_animation, *s_weather4_animation;

static GFont s_info_font;

static AppTimer *timer = NULL;
static AppTimer *timer_2 = NULL;

static int8_t hour;
static int8_t hour1;
static int8_t hour2;
static int8_t minute1;
static int8_t minute2;

static int8_t futurehour;

static int8_t country;
static int16_t degree1;
static int16_t degree2;
static int16_t degree3;
static int16_t degree4;
static int16_t degree5;

static bool night;

static int16_t low;
static int16_t high;

static int16_t conditions1;
static int16_t conditions2;
static int16_t conditions3;
static int16_t conditions4;
static int8_t condcon1;
static int8_t condcon2;
static int8_t condcon3;
static int8_t condcon4;

static int16_t humidity;

int8_t i = 0;

static int16_t bat;
static int16_t Y_bat;

static int8_t first_run = 1;
  
static bool do_hour1;
static bool do_hour2;
static bool do_minute1;
static bool do_minute2;
static bool do_reverse;
static bool shake_reverse;
static bool fore_on = false; 
static bool again = false;
static bool running = false;
static bool animations = true;

static bool bt_connected;

static char s_weather1_buffer[] = "XXXX";
static char s_weather2_buffer[] = "XXXX";
static char s_weather3_buffer[] = "XXXX";
static char s_weather4_buffer[] = "XXXX";
static char s_weather5_buffer[] = "XXXX";
static char s_day_buffer[] = "XXX";
static char s_month_buffer[] = "XXXX";
static char s_date_buffer[] = "XX";
static char s_conditions_buffer[32];
static char s_humidity_buffer[] = "H:XXXX";

const int TIME_RESOURCE_IDS[] = {
  RESOURCE_ID_ZERO,
  RESOURCE_ID_ONE,
  RESOURCE_ID_TWO,
  RESOURCE_ID_THREE,
  RESOURCE_ID_FOUR,
  RESOURCE_ID_FIVE,
  RESOURCE_ID_SIX,
  RESOURCE_ID_SEVEN,
  RESOURCE_ID_EIGHT,
  RESOURCE_ID_NINE
};

const int WEATHER_RESOURCE_IDS[] = {
  RESOURCE_ID_CLEAR,
  RESOURCE_ID_FAIR,
  RESOURCE_ID_MOSTLY_CLOUDY,
  RESOURCE_ID_CLEAR_NIGHT,
  RESOURCE_ID_FAIR_NIGHT,
  RESOURCE_ID_MOSTLY_CLOUDY_NIGHT,
  RESOURCE_ID_CLOUDY,
  RESOURCE_ID_DRIZZLE,
  RESOURCE_ID_SHOWERS,
  RESOURCE_ID_THUNDERSTORMS,
  RESOURCE_ID_FOG,
  RESOURCE_ID_SNOW,
  RESOURCE_ID_HEAVY_SNOW,
  RESOURCE_ID_HAIL,
  RESOURCE_ID_SNOW_HAIL,
  RESOURCE_ID_RAIN_SNOW,
  RESOURCE_ID_RAIN_HAIL,
  RESOURCE_ID_WIND
};

static void do_animation();
static void update_bg(Layer *layer, GContext *ctx);