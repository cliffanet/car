#ifndef __u8g2_fonts_H
#define __u8g2_fonts_H


#include <stdint.h>

/*==========================================*/
/* C++ compatible */

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __GNUC__
#  define U8X8_NOINLINE __attribute__((noinline))
#  define U8X8_SECTION(name) __attribute__ ((section (name)))
#  define U8X8_UNUSED __attribute__((unused))
#else
#  define U8X8_SECTION(name)
#  define U8X8_NOINLINE
#  define U8X8_UNUSED
#endif

#if defined(__GNUC__) && defined(__AVR__)
#  define U8X8_FONT_SECTION(name) U8X8_SECTION(".progmem." name)
#  define u8x8_pgm_read(adr) pgm_read_byte_near(adr)
#  define U8X8_PROGMEM PROGMEM
#endif

#if defined(ESP8266)
uint8_t u8x8_pgm_read_esp(const uint8_t * addr);   /* u8x8_8x8.c */
#  define U8X8_FONT_SECTION(name) __attribute__((section(".text." name)))
#  define u8x8_pgm_read(adr) u8x8_pgm_read_esp(adr)
#  define U8X8_PROGMEM
#endif



#ifndef U8X8_FONT_SECTION
#  define U8X8_FONT_SECTION(name) 
#endif


#define U8G2_FONT_SECTION(name) U8X8_FONT_SECTION(name) 




/*==========================================*/

/* start font list */
extern const uint8_t u8g2_font_u8glib_4_tf[] U8G2_FONT_SECTION("u8g2_font_u8glib_4_tf");
extern const uint8_t u8g2_font_u8glib_4_tr[] U8G2_FONT_SECTION("u8g2_font_u8glib_4_tr");
extern const uint8_t u8g2_font_u8glib_4_hf[] U8G2_FONT_SECTION("u8g2_font_u8glib_4_hf");
extern const uint8_t u8g2_font_u8glib_4_hr[] U8G2_FONT_SECTION("u8g2_font_u8glib_4_hr");
extern const uint8_t u8g2_font_m2icon_5_tf[] U8G2_FONT_SECTION("u8g2_font_m2icon_5_tf");
extern const uint8_t u8g2_font_m2icon_7_tf[] U8G2_FONT_SECTION("u8g2_font_m2icon_7_tf");
extern const uint8_t u8g2_font_m2icon_9_tf[] U8G2_FONT_SECTION("u8g2_font_m2icon_9_tf");
extern const uint8_t u8g2_font_emoticons21_tr[] U8G2_FONT_SECTION("u8g2_font_emoticons21_tr");
extern const uint8_t u8g2_font_battery19_tn[] U8G2_FONT_SECTION("u8g2_font_battery19_tn");
extern const uint8_t u8g2_font_battery24_tr[] U8G2_FONT_SECTION("u8g2_font_battery24_tr");
extern const uint8_t u8g2_font_squeezed_r6_tr[] U8G2_FONT_SECTION("u8g2_font_squeezed_r6_tr");
extern const uint8_t u8g2_font_squeezed_r6_tn[] U8G2_FONT_SECTION("u8g2_font_squeezed_r6_tn");
extern const uint8_t u8g2_font_squeezed_b6_tr[] U8G2_FONT_SECTION("u8g2_font_squeezed_b6_tr");
extern const uint8_t u8g2_font_squeezed_b6_tn[] U8G2_FONT_SECTION("u8g2_font_squeezed_b6_tn");
extern const uint8_t u8g2_font_squeezed_r7_tr[] U8G2_FONT_SECTION("u8g2_font_squeezed_r7_tr");
extern const uint8_t u8g2_font_squeezed_r7_tn[] U8G2_FONT_SECTION("u8g2_font_squeezed_r7_tn");
extern const uint8_t u8g2_font_squeezed_b7_tr[] U8G2_FONT_SECTION("u8g2_font_squeezed_b7_tr");
extern const uint8_t u8g2_font_squeezed_b7_tn[] U8G2_FONT_SECTION("u8g2_font_squeezed_b7_tn");
extern const uint8_t u8g2_font_percent_circle_25_hn[] U8G2_FONT_SECTION("u8g2_font_percent_circle_25_hn");
extern const uint8_t u8g2_font_freedoomr10_tu[] U8G2_FONT_SECTION("u8g2_font_freedoomr10_tu");
extern const uint8_t u8g2_font_freedoomr10_mu[] U8G2_FONT_SECTION("u8g2_font_freedoomr10_mu");
extern const uint8_t u8g2_font_freedoomr25_tn[] U8G2_FONT_SECTION("u8g2_font_freedoomr25_tn");
extern const uint8_t u8g2_font_freedoomr25_mn[] U8G2_FONT_SECTION("u8g2_font_freedoomr25_mn");
extern const uint8_t u8g2_font_7Segments_26x42_mn[] U8G2_FONT_SECTION("u8g2_font_7Segments_26x42_mn");
extern const uint8_t u8g2_font_7_Seg_33x19_mn[] U8G2_FONT_SECTION("u8g2_font_7_Seg_33x19_mn");
extern const uint8_t u8g2_font_7_Seg_41x21_mn[] U8G2_FONT_SECTION("u8g2_font_7_Seg_41x21_mn");
extern const uint8_t u8g2_font_tiny5_tf[] U8G2_FONT_SECTION("u8g2_font_tiny5_tf");
extern const uint8_t u8g2_font_tiny5_tr[] U8G2_FONT_SECTION("u8g2_font_tiny5_tr");
extern const uint8_t u8g2_font_tiny5_te[] U8G2_FONT_SECTION("u8g2_font_tiny5_te");
extern const uint8_t u8g2_font_tiny5_t_all[] U8G2_FONT_SECTION("u8g2_font_tiny5_t_all");
extern const uint8_t u8g2_font_04b_03b_tr[] U8G2_FONT_SECTION("u8g2_font_04b_03b_tr");
extern const uint8_t u8g2_font_04b_03_tr[] U8G2_FONT_SECTION("u8g2_font_04b_03_tr");
extern const uint8_t u8g2_font_amstrad_cpc_extended_8f[] U8G2_FONT_SECTION("u8g2_font_amstrad_cpc_extended_8f");
extern const uint8_t u8g2_font_amstrad_cpc_extended_8r[] U8G2_FONT_SECTION("u8g2_font_amstrad_cpc_extended_8r");
extern const uint8_t u8g2_font_amstrad_cpc_extended_8n[] U8G2_FONT_SECTION("u8g2_font_amstrad_cpc_extended_8n");
extern const uint8_t u8g2_font_amstrad_cpc_extended_8u[] U8G2_FONT_SECTION("u8g2_font_amstrad_cpc_extended_8u");
extern const uint8_t u8g2_font_cursor_tf[] U8G2_FONT_SECTION("u8g2_font_cursor_tf");
extern const uint8_t u8g2_font_cursor_tr[] U8G2_FONT_SECTION("u8g2_font_cursor_tr");
extern const uint8_t u8g2_font_micro_tr[] U8G2_FONT_SECTION("u8g2_font_micro_tr");
extern const uint8_t u8g2_font_micro_tn[] U8G2_FONT_SECTION("u8g2_font_micro_tn");
extern const uint8_t u8g2_font_micro_mr[] U8G2_FONT_SECTION("u8g2_font_micro_mr");
extern const uint8_t u8g2_font_micro_mn[] U8G2_FONT_SECTION("u8g2_font_micro_mn");
extern const uint8_t u8g2_font_4x6_tf[] U8G2_FONT_SECTION("u8g2_font_4x6_tf");
extern const uint8_t u8g2_font_4x6_tr[] U8G2_FONT_SECTION("u8g2_font_4x6_tr");
extern const uint8_t u8g2_font_4x6_tn[] U8G2_FONT_SECTION("u8g2_font_4x6_tn");
extern const uint8_t u8g2_font_4x6_mf[] U8G2_FONT_SECTION("u8g2_font_4x6_mf");
extern const uint8_t u8g2_font_4x6_mr[] U8G2_FONT_SECTION("u8g2_font_4x6_mr");
extern const uint8_t u8g2_font_4x6_mn[] U8G2_FONT_SECTION("u8g2_font_4x6_mn");
extern const uint8_t u8g2_font_4x6_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_4x6_t_cyrillic");
extern const uint8_t u8g2_font_5x7_tf[] U8G2_FONT_SECTION("u8g2_font_5x7_tf");
extern const uint8_t u8g2_font_5x7_tr[] U8G2_FONT_SECTION("u8g2_font_5x7_tr");
extern const uint8_t u8g2_font_5x7_tn[] U8G2_FONT_SECTION("u8g2_font_5x7_tn");
extern const uint8_t u8g2_font_5x7_mf[] U8G2_FONT_SECTION("u8g2_font_5x7_mf");
extern const uint8_t u8g2_font_5x7_mr[] U8G2_FONT_SECTION("u8g2_font_5x7_mr");
extern const uint8_t u8g2_font_5x7_mn[] U8G2_FONT_SECTION("u8g2_font_5x7_mn");
extern const uint8_t u8g2_font_5x7_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_5x7_t_cyrillic");
extern const uint8_t u8g2_font_5x8_tf[] U8G2_FONT_SECTION("u8g2_font_5x8_tf");
extern const uint8_t u8g2_font_5x8_tr[] U8G2_FONT_SECTION("u8g2_font_5x8_tr");
extern const uint8_t u8g2_font_5x8_tn[] U8G2_FONT_SECTION("u8g2_font_5x8_tn");
extern const uint8_t u8g2_font_5x8_mf[] U8G2_FONT_SECTION("u8g2_font_5x8_mf");
extern const uint8_t u8g2_font_5x8_mr[] U8G2_FONT_SECTION("u8g2_font_5x8_mr");
extern const uint8_t u8g2_font_5x8_mn[] U8G2_FONT_SECTION("u8g2_font_5x8_mn");
extern const uint8_t u8g2_font_5x8_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_5x8_t_cyrillic");
extern const uint8_t u8g2_font_6x10_tf[] U8G2_FONT_SECTION("u8g2_font_6x10_tf");
extern const uint8_t u8g2_font_6x10_tr[] U8G2_FONT_SECTION("u8g2_font_6x10_tr");
extern const uint8_t u8g2_font_6x10_tn[] U8G2_FONT_SECTION("u8g2_font_6x10_tn");
extern const uint8_t u8g2_font_6x10_mf[] U8G2_FONT_SECTION("u8g2_font_6x10_mf");
extern const uint8_t u8g2_font_6x10_mr[] U8G2_FONT_SECTION("u8g2_font_6x10_mr");
extern const uint8_t u8g2_font_6x10_mn[] U8G2_FONT_SECTION("u8g2_font_6x10_mn");
extern const uint8_t u8g2_font_6x12_tf[] U8G2_FONT_SECTION("u8g2_font_6x12_tf");
extern const uint8_t u8g2_font_6x12_tr[] U8G2_FONT_SECTION("u8g2_font_6x12_tr");
extern const uint8_t u8g2_font_6x12_tn[] U8G2_FONT_SECTION("u8g2_font_6x12_tn");
extern const uint8_t u8g2_font_6x12_te[] U8G2_FONT_SECTION("u8g2_font_6x12_te");
extern const uint8_t u8g2_font_6x12_mf[] U8G2_FONT_SECTION("u8g2_font_6x12_mf");
extern const uint8_t u8g2_font_6x12_mr[] U8G2_FONT_SECTION("u8g2_font_6x12_mr");
extern const uint8_t u8g2_font_6x12_mn[] U8G2_FONT_SECTION("u8g2_font_6x12_mn");
extern const uint8_t u8g2_font_6x12_me[] U8G2_FONT_SECTION("u8g2_font_6x12_me");
extern const uint8_t u8g2_font_6x12_t_symbols[] U8G2_FONT_SECTION("u8g2_font_6x12_t_symbols");
extern const uint8_t u8g2_font_6x12_m_symbols[] U8G2_FONT_SECTION("u8g2_font_6x12_m_symbols");
extern const uint8_t u8g2_font_6x12_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_6x12_t_cyrillic");
extern const uint8_t u8g2_font_6x13_tf[] U8G2_FONT_SECTION("u8g2_font_6x13_tf");
extern const uint8_t u8g2_font_6x13_tr[] U8G2_FONT_SECTION("u8g2_font_6x13_tr");
extern const uint8_t u8g2_font_6x13_tn[] U8G2_FONT_SECTION("u8g2_font_6x13_tn");
extern const uint8_t u8g2_font_6x13_te[] U8G2_FONT_SECTION("u8g2_font_6x13_te");
extern const uint8_t u8g2_font_6x13_mf[] U8G2_FONT_SECTION("u8g2_font_6x13_mf");
extern const uint8_t u8g2_font_6x13_mr[] U8G2_FONT_SECTION("u8g2_font_6x13_mr");
extern const uint8_t u8g2_font_6x13_mn[] U8G2_FONT_SECTION("u8g2_font_6x13_mn");
extern const uint8_t u8g2_font_6x13_me[] U8G2_FONT_SECTION("u8g2_font_6x13_me");
extern const uint8_t u8g2_font_6x13_t_hebrew[] U8G2_FONT_SECTION("u8g2_font_6x13_t_hebrew");
extern const uint8_t u8g2_font_6x13_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_6x13_t_cyrillic");
extern const uint8_t u8g2_font_6x13B_tf[] U8G2_FONT_SECTION("u8g2_font_6x13B_tf");
extern const uint8_t u8g2_font_6x13B_tr[] U8G2_FONT_SECTION("u8g2_font_6x13B_tr");
extern const uint8_t u8g2_font_6x13B_tn[] U8G2_FONT_SECTION("u8g2_font_6x13B_tn");
extern const uint8_t u8g2_font_6x13B_mf[] U8G2_FONT_SECTION("u8g2_font_6x13B_mf");
extern const uint8_t u8g2_font_6x13B_mr[] U8G2_FONT_SECTION("u8g2_font_6x13B_mr");
extern const uint8_t u8g2_font_6x13B_mn[] U8G2_FONT_SECTION("u8g2_font_6x13B_mn");
extern const uint8_t u8g2_font_6x13B_t_hebrew[] U8G2_FONT_SECTION("u8g2_font_6x13B_t_hebrew");
extern const uint8_t u8g2_font_6x13B_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_6x13B_t_cyrillic");
extern const uint8_t u8g2_font_6x13O_tf[] U8G2_FONT_SECTION("u8g2_font_6x13O_tf");
extern const uint8_t u8g2_font_6x13O_tr[] U8G2_FONT_SECTION("u8g2_font_6x13O_tr");
extern const uint8_t u8g2_font_6x13O_tn[] U8G2_FONT_SECTION("u8g2_font_6x13O_tn");
extern const uint8_t u8g2_font_6x13O_mf[] U8G2_FONT_SECTION("u8g2_font_6x13O_mf");
extern const uint8_t u8g2_font_6x13O_mr[] U8G2_FONT_SECTION("u8g2_font_6x13O_mr");
extern const uint8_t u8g2_font_6x13O_mn[] U8G2_FONT_SECTION("u8g2_font_6x13O_mn");
extern const uint8_t u8g2_font_7x13_tf[] U8G2_FONT_SECTION("u8g2_font_7x13_tf");
extern const uint8_t u8g2_font_7x13_tr[] U8G2_FONT_SECTION("u8g2_font_7x13_tr");
extern const uint8_t u8g2_font_7x13_tn[] U8G2_FONT_SECTION("u8g2_font_7x13_tn");
extern const uint8_t u8g2_font_7x13_te[] U8G2_FONT_SECTION("u8g2_font_7x13_te");
extern const uint8_t u8g2_font_7x13_mf[] U8G2_FONT_SECTION("u8g2_font_7x13_mf");
extern const uint8_t u8g2_font_7x13_mr[] U8G2_FONT_SECTION("u8g2_font_7x13_mr");
extern const uint8_t u8g2_font_7x13_mn[] U8G2_FONT_SECTION("u8g2_font_7x13_mn");
extern const uint8_t u8g2_font_7x13_me[] U8G2_FONT_SECTION("u8g2_font_7x13_me");
extern const uint8_t u8g2_font_7x13_t_symbols[] U8G2_FONT_SECTION("u8g2_font_7x13_t_symbols");
extern const uint8_t u8g2_font_7x13_m_symbols[] U8G2_FONT_SECTION("u8g2_font_7x13_m_symbols");
extern const uint8_t u8g2_font_7x13_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_7x13_t_cyrillic");
extern const uint8_t u8g2_font_7x13B_tf[] U8G2_FONT_SECTION("u8g2_font_7x13B_tf");
extern const uint8_t u8g2_font_7x13B_tr[] U8G2_FONT_SECTION("u8g2_font_7x13B_tr");
extern const uint8_t u8g2_font_7x13B_tn[] U8G2_FONT_SECTION("u8g2_font_7x13B_tn");
extern const uint8_t u8g2_font_7x13B_mf[] U8G2_FONT_SECTION("u8g2_font_7x13B_mf");
extern const uint8_t u8g2_font_7x13B_mr[] U8G2_FONT_SECTION("u8g2_font_7x13B_mr");
extern const uint8_t u8g2_font_7x13B_mn[] U8G2_FONT_SECTION("u8g2_font_7x13B_mn");
extern const uint8_t u8g2_font_7x13O_tf[] U8G2_FONT_SECTION("u8g2_font_7x13O_tf");
extern const uint8_t u8g2_font_7x13O_tr[] U8G2_FONT_SECTION("u8g2_font_7x13O_tr");
extern const uint8_t u8g2_font_7x13O_tn[] U8G2_FONT_SECTION("u8g2_font_7x13O_tn");
extern const uint8_t u8g2_font_7x13O_mf[] U8G2_FONT_SECTION("u8g2_font_7x13O_mf");
extern const uint8_t u8g2_font_7x13O_mr[] U8G2_FONT_SECTION("u8g2_font_7x13O_mr");
extern const uint8_t u8g2_font_7x13O_mn[] U8G2_FONT_SECTION("u8g2_font_7x13O_mn");
extern const uint8_t u8g2_font_7x14_tf[] U8G2_FONT_SECTION("u8g2_font_7x14_tf");
extern const uint8_t u8g2_font_7x14_tr[] U8G2_FONT_SECTION("u8g2_font_7x14_tr");
extern const uint8_t u8g2_font_7x14_tn[] U8G2_FONT_SECTION("u8g2_font_7x14_tn");
extern const uint8_t u8g2_font_7x14_mf[] U8G2_FONT_SECTION("u8g2_font_7x14_mf");
extern const uint8_t u8g2_font_7x14_mr[] U8G2_FONT_SECTION("u8g2_font_7x14_mr");
extern const uint8_t u8g2_font_7x14_mn[] U8G2_FONT_SECTION("u8g2_font_7x14_mn");
extern const uint8_t u8g2_font_7x14B_tf[] U8G2_FONT_SECTION("u8g2_font_7x14B_tf");
extern const uint8_t u8g2_font_7x14B_tr[] U8G2_FONT_SECTION("u8g2_font_7x14B_tr");
extern const uint8_t u8g2_font_7x14B_tn[] U8G2_FONT_SECTION("u8g2_font_7x14B_tn");
extern const uint8_t u8g2_font_7x14B_mf[] U8G2_FONT_SECTION("u8g2_font_7x14B_mf");
extern const uint8_t u8g2_font_7x14B_mr[] U8G2_FONT_SECTION("u8g2_font_7x14B_mr");
extern const uint8_t u8g2_font_7x14B_mn[] U8G2_FONT_SECTION("u8g2_font_7x14B_mn");
extern const uint8_t u8g2_font_8x13_tf[] U8G2_FONT_SECTION("u8g2_font_8x13_tf");
extern const uint8_t u8g2_font_8x13_tr[] U8G2_FONT_SECTION("u8g2_font_8x13_tr");
extern const uint8_t u8g2_font_8x13_tn[] U8G2_FONT_SECTION("u8g2_font_8x13_tn");
extern const uint8_t u8g2_font_8x13_te[] U8G2_FONT_SECTION("u8g2_font_8x13_te");
extern const uint8_t u8g2_font_8x13_mf[] U8G2_FONT_SECTION("u8g2_font_8x13_mf");
extern const uint8_t u8g2_font_8x13_mr[] U8G2_FONT_SECTION("u8g2_font_8x13_mr");
extern const uint8_t u8g2_font_8x13_mn[] U8G2_FONT_SECTION("u8g2_font_8x13_mn");
extern const uint8_t u8g2_font_8x13_me[] U8G2_FONT_SECTION("u8g2_font_8x13_me");
extern const uint8_t u8g2_font_8x13_t_symbols[] U8G2_FONT_SECTION("u8g2_font_8x13_t_symbols");
extern const uint8_t u8g2_font_8x13_m_symbols[] U8G2_FONT_SECTION("u8g2_font_8x13_m_symbols");
extern const uint8_t u8g2_font_8x13_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_8x13_t_cyrillic");
extern const uint8_t u8g2_font_8x13B_tf[] U8G2_FONT_SECTION("u8g2_font_8x13B_tf");
extern const uint8_t u8g2_font_8x13B_tr[] U8G2_FONT_SECTION("u8g2_font_8x13B_tr");
extern const uint8_t u8g2_font_8x13B_tn[] U8G2_FONT_SECTION("u8g2_font_8x13B_tn");
extern const uint8_t u8g2_font_8x13B_mf[] U8G2_FONT_SECTION("u8g2_font_8x13B_mf");
extern const uint8_t u8g2_font_8x13B_mr[] U8G2_FONT_SECTION("u8g2_font_8x13B_mr");
extern const uint8_t u8g2_font_8x13B_mn[] U8G2_FONT_SECTION("u8g2_font_8x13B_mn");
extern const uint8_t u8g2_font_8x13O_tf[] U8G2_FONT_SECTION("u8g2_font_8x13O_tf");
extern const uint8_t u8g2_font_8x13O_tr[] U8G2_FONT_SECTION("u8g2_font_8x13O_tr");
extern const uint8_t u8g2_font_8x13O_tn[] U8G2_FONT_SECTION("u8g2_font_8x13O_tn");
extern const uint8_t u8g2_font_8x13O_mf[] U8G2_FONT_SECTION("u8g2_font_8x13O_mf");
extern const uint8_t u8g2_font_8x13O_mr[] U8G2_FONT_SECTION("u8g2_font_8x13O_mr");
extern const uint8_t u8g2_font_8x13O_mn[] U8G2_FONT_SECTION("u8g2_font_8x13O_mn");
extern const uint8_t u8g2_font_9x15_tf[] U8G2_FONT_SECTION("u8g2_font_9x15_tf");
extern const uint8_t u8g2_font_9x15_tr[] U8G2_FONT_SECTION("u8g2_font_9x15_tr");
extern const uint8_t u8g2_font_9x15_tn[] U8G2_FONT_SECTION("u8g2_font_9x15_tn");
extern const uint8_t u8g2_font_9x15_te[] U8G2_FONT_SECTION("u8g2_font_9x15_te");
extern const uint8_t u8g2_font_9x15_mf[] U8G2_FONT_SECTION("u8g2_font_9x15_mf");
extern const uint8_t u8g2_font_9x15_mr[] U8G2_FONT_SECTION("u8g2_font_9x15_mr");
extern const uint8_t u8g2_font_9x15_mn[] U8G2_FONT_SECTION("u8g2_font_9x15_mn");
extern const uint8_t u8g2_font_9x15_me[] U8G2_FONT_SECTION("u8g2_font_9x15_me");
extern const uint8_t u8g2_font_9x15_t_symbols[] U8G2_FONT_SECTION("u8g2_font_9x15_t_symbols");
extern const uint8_t u8g2_font_9x15_m_symbols[] U8G2_FONT_SECTION("u8g2_font_9x15_m_symbols");
extern const uint8_t u8g2_font_9x15_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_9x15_t_cyrillic");
extern const uint8_t u8g2_font_9x15B_tf[] U8G2_FONT_SECTION("u8g2_font_9x15B_tf");
extern const uint8_t u8g2_font_9x15B_tr[] U8G2_FONT_SECTION("u8g2_font_9x15B_tr");
extern const uint8_t u8g2_font_9x15B_tn[] U8G2_FONT_SECTION("u8g2_font_9x15B_tn");
extern const uint8_t u8g2_font_9x15B_mf[] U8G2_FONT_SECTION("u8g2_font_9x15B_mf");
extern const uint8_t u8g2_font_9x15B_mr[] U8G2_FONT_SECTION("u8g2_font_9x15B_mr");
extern const uint8_t u8g2_font_9x15B_mn[] U8G2_FONT_SECTION("u8g2_font_9x15B_mn");
extern const uint8_t u8g2_font_9x18_tf[] U8G2_FONT_SECTION("u8g2_font_9x18_tf");
extern const uint8_t u8g2_font_9x18_tr[] U8G2_FONT_SECTION("u8g2_font_9x18_tr");
extern const uint8_t u8g2_font_9x18_tn[] U8G2_FONT_SECTION("u8g2_font_9x18_tn");
extern const uint8_t u8g2_font_9x18_mf[] U8G2_FONT_SECTION("u8g2_font_9x18_mf");
extern const uint8_t u8g2_font_9x18_mr[] U8G2_FONT_SECTION("u8g2_font_9x18_mr");
extern const uint8_t u8g2_font_9x18_mn[] U8G2_FONT_SECTION("u8g2_font_9x18_mn");
extern const uint8_t u8g2_font_9x18B_tf[] U8G2_FONT_SECTION("u8g2_font_9x18B_tf");
extern const uint8_t u8g2_font_9x18B_tr[] U8G2_FONT_SECTION("u8g2_font_9x18B_tr");
extern const uint8_t u8g2_font_9x18B_tn[] U8G2_FONT_SECTION("u8g2_font_9x18B_tn");
extern const uint8_t u8g2_font_9x18B_mf[] U8G2_FONT_SECTION("u8g2_font_9x18B_mf");
extern const uint8_t u8g2_font_9x18B_mr[] U8G2_FONT_SECTION("u8g2_font_9x18B_mr");
extern const uint8_t u8g2_font_9x18B_mn[] U8G2_FONT_SECTION("u8g2_font_9x18B_mn");
extern const uint8_t u8g2_font_10x20_tf[] U8G2_FONT_SECTION("u8g2_font_10x20_tf");
extern const uint8_t u8g2_font_10x20_tr[] U8G2_FONT_SECTION("u8g2_font_10x20_tr");
extern const uint8_t u8g2_font_10x20_tn[] U8G2_FONT_SECTION("u8g2_font_10x20_tn");
extern const uint8_t u8g2_font_10x20_te[] U8G2_FONT_SECTION("u8g2_font_10x20_te");
extern const uint8_t u8g2_font_10x20_mf[] U8G2_FONT_SECTION("u8g2_font_10x20_mf");
extern const uint8_t u8g2_font_10x20_mr[] U8G2_FONT_SECTION("u8g2_font_10x20_mr");
extern const uint8_t u8g2_font_10x20_mn[] U8G2_FONT_SECTION("u8g2_font_10x20_mn");
extern const uint8_t u8g2_font_10x20_me[] U8G2_FONT_SECTION("u8g2_font_10x20_me");
extern const uint8_t u8g2_font_10x20_t_greek[] U8G2_FONT_SECTION("u8g2_font_10x20_t_greek");
extern const uint8_t u8g2_font_10x20_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_10x20_t_cyrillic");
extern const uint8_t u8g2_font_10x20_t_arabic[] U8G2_FONT_SECTION("u8g2_font_10x20_t_arabic");
extern const uint8_t u8g2_font_siji_t_6x10[] U8G2_FONT_SECTION("u8g2_font_siji_t_6x10");
extern const uint8_t u8g2_font_waffle_t_all[] U8G2_FONT_SECTION("u8g2_font_waffle_t_all");
extern const uint8_t u8g2_font_tom_thumb_4x6_t_all[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_t_all");
extern const uint8_t u8g2_font_tom_thumb_4x6_tf[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_tf");
extern const uint8_t u8g2_font_tom_thumb_4x6_tr[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_tr");
extern const uint8_t u8g2_font_tom_thumb_4x6_tn[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_tn");
extern const uint8_t u8g2_font_tom_thumb_4x6_te[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_te");
extern const uint8_t u8g2_font_tom_thumb_4x6_mf[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_mf");
extern const uint8_t u8g2_font_tom_thumb_4x6_mr[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_mr");
extern const uint8_t u8g2_font_tom_thumb_4x6_mn[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_mn");
extern const uint8_t u8g2_font_tom_thumb_4x6_me[] U8G2_FONT_SECTION("u8g2_font_tom_thumb_4x6_me");
extern const uint8_t u8g2_font_mystery_quest_24_tf[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_24_tf");
extern const uint8_t u8g2_font_mystery_quest_24_tr[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_24_tr");
extern const uint8_t u8g2_font_mystery_quest_24_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_24_tn");
extern const uint8_t u8g2_font_mystery_quest_28_tf[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_28_tf");
extern const uint8_t u8g2_font_mystery_quest_28_tr[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_28_tr");
extern const uint8_t u8g2_font_mystery_quest_28_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_28_tn");
extern const uint8_t u8g2_font_mystery_quest_32_tr[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_32_tr");
extern const uint8_t u8g2_font_mystery_quest_32_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_32_tn");
extern const uint8_t u8g2_font_mystery_quest_36_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_36_tn");
extern const uint8_t u8g2_font_mystery_quest_42_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_42_tn");
extern const uint8_t u8g2_font_mystery_quest_48_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_48_tn");
extern const uint8_t u8g2_font_mystery_quest_56_tn[] U8G2_FONT_SECTION("u8g2_font_mystery_quest_56_tn");
extern const uint8_t u8g2_font_t0_11_tf[] U8G2_FONT_SECTION("u8g2_font_t0_11_tf");
extern const uint8_t u8g2_font_t0_11_tr[] U8G2_FONT_SECTION("u8g2_font_t0_11_tr");
extern const uint8_t u8g2_font_t0_11_tn[] U8G2_FONT_SECTION("u8g2_font_t0_11_tn");
extern const uint8_t u8g2_font_t0_11_te[] U8G2_FONT_SECTION("u8g2_font_t0_11_te");
extern const uint8_t u8g2_font_t0_11_mf[] U8G2_FONT_SECTION("u8g2_font_t0_11_mf");
extern const uint8_t u8g2_font_t0_11_mr[] U8G2_FONT_SECTION("u8g2_font_t0_11_mr");
extern const uint8_t u8g2_font_t0_11_mn[] U8G2_FONT_SECTION("u8g2_font_t0_11_mn");
extern const uint8_t u8g2_font_t0_11_me[] U8G2_FONT_SECTION("u8g2_font_t0_11_me");
extern const uint8_t u8g2_font_t0_11_t_all[] U8G2_FONT_SECTION("u8g2_font_t0_11_t_all");
extern const uint8_t u8g2_font_t0_11b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_11b_tf");
extern const uint8_t u8g2_font_t0_11b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_11b_tr");
extern const uint8_t u8g2_font_t0_11b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_11b_tn");
extern const uint8_t u8g2_font_t0_11b_te[] U8G2_FONT_SECTION("u8g2_font_t0_11b_te");
extern const uint8_t u8g2_font_t0_11b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_11b_mf");
extern const uint8_t u8g2_font_t0_11b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_11b_mr");
extern const uint8_t u8g2_font_t0_11b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_11b_mn");
extern const uint8_t u8g2_font_t0_11b_me[] U8G2_FONT_SECTION("u8g2_font_t0_11b_me");
extern const uint8_t u8g2_font_t0_12_tf[] U8G2_FONT_SECTION("u8g2_font_t0_12_tf");
extern const uint8_t u8g2_font_t0_12_tr[] U8G2_FONT_SECTION("u8g2_font_t0_12_tr");
extern const uint8_t u8g2_font_t0_12_tn[] U8G2_FONT_SECTION("u8g2_font_t0_12_tn");
extern const uint8_t u8g2_font_t0_12_te[] U8G2_FONT_SECTION("u8g2_font_t0_12_te");
extern const uint8_t u8g2_font_t0_12_mf[] U8G2_FONT_SECTION("u8g2_font_t0_12_mf");
extern const uint8_t u8g2_font_t0_12_mr[] U8G2_FONT_SECTION("u8g2_font_t0_12_mr");
extern const uint8_t u8g2_font_t0_12_mn[] U8G2_FONT_SECTION("u8g2_font_t0_12_mn");
extern const uint8_t u8g2_font_t0_12_me[] U8G2_FONT_SECTION("u8g2_font_t0_12_me");
extern const uint8_t u8g2_font_t0_12b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_12b_tf");
extern const uint8_t u8g2_font_t0_12b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_12b_tr");
extern const uint8_t u8g2_font_t0_12b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_12b_tn");
extern const uint8_t u8g2_font_t0_12b_te[] U8G2_FONT_SECTION("u8g2_font_t0_12b_te");
extern const uint8_t u8g2_font_t0_12b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_12b_mf");
extern const uint8_t u8g2_font_t0_12b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_12b_mr");
extern const uint8_t u8g2_font_t0_12b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_12b_mn");
extern const uint8_t u8g2_font_t0_12b_me[] U8G2_FONT_SECTION("u8g2_font_t0_12b_me");
extern const uint8_t u8g2_font_t0_13_tf[] U8G2_FONT_SECTION("u8g2_font_t0_13_tf");
extern const uint8_t u8g2_font_t0_13_tr[] U8G2_FONT_SECTION("u8g2_font_t0_13_tr");
extern const uint8_t u8g2_font_t0_13_tn[] U8G2_FONT_SECTION("u8g2_font_t0_13_tn");
extern const uint8_t u8g2_font_t0_13_te[] U8G2_FONT_SECTION("u8g2_font_t0_13_te");
extern const uint8_t u8g2_font_t0_13_mf[] U8G2_FONT_SECTION("u8g2_font_t0_13_mf");
extern const uint8_t u8g2_font_t0_13_mr[] U8G2_FONT_SECTION("u8g2_font_t0_13_mr");
extern const uint8_t u8g2_font_t0_13_mn[] U8G2_FONT_SECTION("u8g2_font_t0_13_mn");
extern const uint8_t u8g2_font_t0_13_me[] U8G2_FONT_SECTION("u8g2_font_t0_13_me");
extern const uint8_t u8g2_font_t0_13b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_13b_tf");
extern const uint8_t u8g2_font_t0_13b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_13b_tr");
extern const uint8_t u8g2_font_t0_13b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_13b_tn");
extern const uint8_t u8g2_font_t0_13b_te[] U8G2_FONT_SECTION("u8g2_font_t0_13b_te");
extern const uint8_t u8g2_font_t0_13b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_13b_mf");
extern const uint8_t u8g2_font_t0_13b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_13b_mr");
extern const uint8_t u8g2_font_t0_13b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_13b_mn");
extern const uint8_t u8g2_font_t0_13b_me[] U8G2_FONT_SECTION("u8g2_font_t0_13b_me");
extern const uint8_t u8g2_font_t0_14_tf[] U8G2_FONT_SECTION("u8g2_font_t0_14_tf");
extern const uint8_t u8g2_font_t0_14_tr[] U8G2_FONT_SECTION("u8g2_font_t0_14_tr");
extern const uint8_t u8g2_font_t0_14_tn[] U8G2_FONT_SECTION("u8g2_font_t0_14_tn");
extern const uint8_t u8g2_font_t0_14_te[] U8G2_FONT_SECTION("u8g2_font_t0_14_te");
extern const uint8_t u8g2_font_t0_14_mf[] U8G2_FONT_SECTION("u8g2_font_t0_14_mf");
extern const uint8_t u8g2_font_t0_14_mr[] U8G2_FONT_SECTION("u8g2_font_t0_14_mr");
extern const uint8_t u8g2_font_t0_14_mn[] U8G2_FONT_SECTION("u8g2_font_t0_14_mn");
extern const uint8_t u8g2_font_t0_14_me[] U8G2_FONT_SECTION("u8g2_font_t0_14_me");
extern const uint8_t u8g2_font_t0_14b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_14b_tf");
extern const uint8_t u8g2_font_t0_14b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_14b_tr");
extern const uint8_t u8g2_font_t0_14b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_14b_tn");
extern const uint8_t u8g2_font_t0_14b_te[] U8G2_FONT_SECTION("u8g2_font_t0_14b_te");
extern const uint8_t u8g2_font_t0_14b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_14b_mf");
extern const uint8_t u8g2_font_t0_14b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_14b_mr");
extern const uint8_t u8g2_font_t0_14b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_14b_mn");
extern const uint8_t u8g2_font_t0_14b_me[] U8G2_FONT_SECTION("u8g2_font_t0_14b_me");
extern const uint8_t u8g2_font_t0_15_tf[] U8G2_FONT_SECTION("u8g2_font_t0_15_tf");
extern const uint8_t u8g2_font_t0_15_tr[] U8G2_FONT_SECTION("u8g2_font_t0_15_tr");
extern const uint8_t u8g2_font_t0_15_tn[] U8G2_FONT_SECTION("u8g2_font_t0_15_tn");
extern const uint8_t u8g2_font_t0_15_te[] U8G2_FONT_SECTION("u8g2_font_t0_15_te");
extern const uint8_t u8g2_font_t0_15_mf[] U8G2_FONT_SECTION("u8g2_font_t0_15_mf");
extern const uint8_t u8g2_font_t0_15_mr[] U8G2_FONT_SECTION("u8g2_font_t0_15_mr");
extern const uint8_t u8g2_font_t0_15_mn[] U8G2_FONT_SECTION("u8g2_font_t0_15_mn");
extern const uint8_t u8g2_font_t0_15_me[] U8G2_FONT_SECTION("u8g2_font_t0_15_me");
extern const uint8_t u8g2_font_t0_15b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_15b_tf");
extern const uint8_t u8g2_font_t0_15b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_15b_tr");
extern const uint8_t u8g2_font_t0_15b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_15b_tn");
extern const uint8_t u8g2_font_t0_15b_te[] U8G2_FONT_SECTION("u8g2_font_t0_15b_te");
extern const uint8_t u8g2_font_t0_15b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_15b_mf");
extern const uint8_t u8g2_font_t0_15b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_15b_mr");
extern const uint8_t u8g2_font_t0_15b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_15b_mn");
extern const uint8_t u8g2_font_t0_15b_me[] U8G2_FONT_SECTION("u8g2_font_t0_15b_me");
extern const uint8_t u8g2_font_t0_16_tf[] U8G2_FONT_SECTION("u8g2_font_t0_16_tf");
extern const uint8_t u8g2_font_t0_16_tr[] U8G2_FONT_SECTION("u8g2_font_t0_16_tr");
extern const uint8_t u8g2_font_t0_16_tn[] U8G2_FONT_SECTION("u8g2_font_t0_16_tn");
extern const uint8_t u8g2_font_t0_16_te[] U8G2_FONT_SECTION("u8g2_font_t0_16_te");
extern const uint8_t u8g2_font_t0_16_mf[] U8G2_FONT_SECTION("u8g2_font_t0_16_mf");
extern const uint8_t u8g2_font_t0_16_mr[] U8G2_FONT_SECTION("u8g2_font_t0_16_mr");
extern const uint8_t u8g2_font_t0_16_mn[] U8G2_FONT_SECTION("u8g2_font_t0_16_mn");
extern const uint8_t u8g2_font_t0_16_me[] U8G2_FONT_SECTION("u8g2_font_t0_16_me");
extern const uint8_t u8g2_font_t0_16b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_16b_tf");
extern const uint8_t u8g2_font_t0_16b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_16b_tr");
extern const uint8_t u8g2_font_t0_16b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_16b_tn");
extern const uint8_t u8g2_font_t0_16b_te[] U8G2_FONT_SECTION("u8g2_font_t0_16b_te");
extern const uint8_t u8g2_font_t0_16b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_16b_mf");
extern const uint8_t u8g2_font_t0_16b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_16b_mr");
extern const uint8_t u8g2_font_t0_16b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_16b_mn");
extern const uint8_t u8g2_font_t0_16b_me[] U8G2_FONT_SECTION("u8g2_font_t0_16b_me");
extern const uint8_t u8g2_font_t0_17_tf[] U8G2_FONT_SECTION("u8g2_font_t0_17_tf");
extern const uint8_t u8g2_font_t0_17_tr[] U8G2_FONT_SECTION("u8g2_font_t0_17_tr");
extern const uint8_t u8g2_font_t0_17_tn[] U8G2_FONT_SECTION("u8g2_font_t0_17_tn");
extern const uint8_t u8g2_font_t0_17_te[] U8G2_FONT_SECTION("u8g2_font_t0_17_te");
extern const uint8_t u8g2_font_t0_17_mf[] U8G2_FONT_SECTION("u8g2_font_t0_17_mf");
extern const uint8_t u8g2_font_t0_17_mr[] U8G2_FONT_SECTION("u8g2_font_t0_17_mr");
extern const uint8_t u8g2_font_t0_17_mn[] U8G2_FONT_SECTION("u8g2_font_t0_17_mn");
extern const uint8_t u8g2_font_t0_17_me[] U8G2_FONT_SECTION("u8g2_font_t0_17_me");
extern const uint8_t u8g2_font_t0_17b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_17b_tf");
extern const uint8_t u8g2_font_t0_17b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_17b_tr");
extern const uint8_t u8g2_font_t0_17b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_17b_tn");
extern const uint8_t u8g2_font_t0_17b_te[] U8G2_FONT_SECTION("u8g2_font_t0_17b_te");
extern const uint8_t u8g2_font_t0_17b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_17b_mf");
extern const uint8_t u8g2_font_t0_17b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_17b_mr");
extern const uint8_t u8g2_font_t0_17b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_17b_mn");
extern const uint8_t u8g2_font_t0_17b_me[] U8G2_FONT_SECTION("u8g2_font_t0_17b_me");
extern const uint8_t u8g2_font_t0_18_tf[] U8G2_FONT_SECTION("u8g2_font_t0_18_tf");
extern const uint8_t u8g2_font_t0_18_tr[] U8G2_FONT_SECTION("u8g2_font_t0_18_tr");
extern const uint8_t u8g2_font_t0_18_tn[] U8G2_FONT_SECTION("u8g2_font_t0_18_tn");
extern const uint8_t u8g2_font_t0_18_te[] U8G2_FONT_SECTION("u8g2_font_t0_18_te");
extern const uint8_t u8g2_font_t0_18_mf[] U8G2_FONT_SECTION("u8g2_font_t0_18_mf");
extern const uint8_t u8g2_font_t0_18_mr[] U8G2_FONT_SECTION("u8g2_font_t0_18_mr");
extern const uint8_t u8g2_font_t0_18_mn[] U8G2_FONT_SECTION("u8g2_font_t0_18_mn");
extern const uint8_t u8g2_font_t0_18_me[] U8G2_FONT_SECTION("u8g2_font_t0_18_me");
extern const uint8_t u8g2_font_t0_18b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_18b_tf");
extern const uint8_t u8g2_font_t0_18b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_18b_tr");
extern const uint8_t u8g2_font_t0_18b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_18b_tn");
extern const uint8_t u8g2_font_t0_18b_te[] U8G2_FONT_SECTION("u8g2_font_t0_18b_te");
extern const uint8_t u8g2_font_t0_18b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_18b_mf");
extern const uint8_t u8g2_font_t0_18b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_18b_mr");
extern const uint8_t u8g2_font_t0_18b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_18b_mn");
extern const uint8_t u8g2_font_t0_18b_me[] U8G2_FONT_SECTION("u8g2_font_t0_18b_me");
extern const uint8_t u8g2_font_t0_22_tf[] U8G2_FONT_SECTION("u8g2_font_t0_22_tf");
extern const uint8_t u8g2_font_t0_22_tr[] U8G2_FONT_SECTION("u8g2_font_t0_22_tr");
extern const uint8_t u8g2_font_t0_22_tn[] U8G2_FONT_SECTION("u8g2_font_t0_22_tn");
extern const uint8_t u8g2_font_t0_22_te[] U8G2_FONT_SECTION("u8g2_font_t0_22_te");
extern const uint8_t u8g2_font_t0_22_mf[] U8G2_FONT_SECTION("u8g2_font_t0_22_mf");
extern const uint8_t u8g2_font_t0_22_mr[] U8G2_FONT_SECTION("u8g2_font_t0_22_mr");
extern const uint8_t u8g2_font_t0_22_mn[] U8G2_FONT_SECTION("u8g2_font_t0_22_mn");
extern const uint8_t u8g2_font_t0_22_me[] U8G2_FONT_SECTION("u8g2_font_t0_22_me");
extern const uint8_t u8g2_font_t0_22b_tf[] U8G2_FONT_SECTION("u8g2_font_t0_22b_tf");
extern const uint8_t u8g2_font_t0_22b_tr[] U8G2_FONT_SECTION("u8g2_font_t0_22b_tr");
extern const uint8_t u8g2_font_t0_22b_tn[] U8G2_FONT_SECTION("u8g2_font_t0_22b_tn");
extern const uint8_t u8g2_font_t0_22b_te[] U8G2_FONT_SECTION("u8g2_font_t0_22b_te");
extern const uint8_t u8g2_font_t0_22b_mf[] U8G2_FONT_SECTION("u8g2_font_t0_22b_mf");
extern const uint8_t u8g2_font_t0_22b_mr[] U8G2_FONT_SECTION("u8g2_font_t0_22b_mr");
extern const uint8_t u8g2_font_t0_22b_mn[] U8G2_FONT_SECTION("u8g2_font_t0_22b_mn");
extern const uint8_t u8g2_font_t0_22b_me[] U8G2_FONT_SECTION("u8g2_font_t0_22b_me");
extern const uint8_t u8g2_font_open_iconic_all_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_all_1x_t");
extern const uint8_t u8g2_font_open_iconic_app_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_app_1x_t");
extern const uint8_t u8g2_font_open_iconic_arrow_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_arrow_1x_t");
extern const uint8_t u8g2_font_open_iconic_check_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_check_1x_t");
extern const uint8_t u8g2_font_open_iconic_email_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_email_1x_t");
extern const uint8_t u8g2_font_open_iconic_embedded_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_embedded_1x_t");
extern const uint8_t u8g2_font_open_iconic_gui_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_gui_1x_t");
extern const uint8_t u8g2_font_open_iconic_human_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_human_1x_t");
extern const uint8_t u8g2_font_open_iconic_mime_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_mime_1x_t");
extern const uint8_t u8g2_font_open_iconic_other_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_other_1x_t");
extern const uint8_t u8g2_font_open_iconic_play_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_play_1x_t");
extern const uint8_t u8g2_font_open_iconic_text_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_text_1x_t");
extern const uint8_t u8g2_font_open_iconic_thing_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_thing_1x_t");
extern const uint8_t u8g2_font_open_iconic_weather_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_weather_1x_t");
extern const uint8_t u8g2_font_open_iconic_www_1x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_www_1x_t");
extern const uint8_t u8g2_font_open_iconic_all_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_all_2x_t");
extern const uint8_t u8g2_font_open_iconic_app_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_app_2x_t");
extern const uint8_t u8g2_font_open_iconic_arrow_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_arrow_2x_t");
extern const uint8_t u8g2_font_open_iconic_check_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_check_2x_t");
extern const uint8_t u8g2_font_open_iconic_email_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_email_2x_t");
extern const uint8_t u8g2_font_open_iconic_embedded_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_embedded_2x_t");
extern const uint8_t u8g2_font_open_iconic_gui_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_gui_2x_t");
extern const uint8_t u8g2_font_open_iconic_human_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_human_2x_t");
extern const uint8_t u8g2_font_open_iconic_mime_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_mime_2x_t");
extern const uint8_t u8g2_font_open_iconic_other_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_other_2x_t");
extern const uint8_t u8g2_font_open_iconic_play_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_play_2x_t");
extern const uint8_t u8g2_font_open_iconic_text_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_text_2x_t");
extern const uint8_t u8g2_font_open_iconic_thing_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_thing_2x_t");
extern const uint8_t u8g2_font_open_iconic_weather_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_weather_2x_t");
extern const uint8_t u8g2_font_open_iconic_www_2x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_www_2x_t");
extern const uint8_t u8g2_font_open_iconic_all_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_all_4x_t");
extern const uint8_t u8g2_font_open_iconic_app_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_app_4x_t");
extern const uint8_t u8g2_font_open_iconic_arrow_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_arrow_4x_t");
extern const uint8_t u8g2_font_open_iconic_check_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_check_4x_t");
extern const uint8_t u8g2_font_open_iconic_email_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_email_4x_t");
extern const uint8_t u8g2_font_open_iconic_embedded_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_embedded_4x_t");
extern const uint8_t u8g2_font_open_iconic_gui_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_gui_4x_t");
extern const uint8_t u8g2_font_open_iconic_human_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_human_4x_t");
extern const uint8_t u8g2_font_open_iconic_mime_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_mime_4x_t");
extern const uint8_t u8g2_font_open_iconic_other_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_other_4x_t");
extern const uint8_t u8g2_font_open_iconic_play_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_play_4x_t");
extern const uint8_t u8g2_font_open_iconic_text_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_text_4x_t");
extern const uint8_t u8g2_font_open_iconic_thing_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_thing_4x_t");
extern const uint8_t u8g2_font_open_iconic_weather_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_weather_4x_t");
extern const uint8_t u8g2_font_open_iconic_www_4x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_www_4x_t");
extern const uint8_t u8g2_font_open_iconic_all_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_all_6x_t");
extern const uint8_t u8g2_font_open_iconic_app_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_app_6x_t");
extern const uint8_t u8g2_font_open_iconic_arrow_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_arrow_6x_t");
extern const uint8_t u8g2_font_open_iconic_check_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_check_6x_t");
extern const uint8_t u8g2_font_open_iconic_email_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_email_6x_t");
extern const uint8_t u8g2_font_open_iconic_embedded_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_embedded_6x_t");
extern const uint8_t u8g2_font_open_iconic_gui_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_gui_6x_t");
extern const uint8_t u8g2_font_open_iconic_human_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_human_6x_t");
extern const uint8_t u8g2_font_open_iconic_mime_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_mime_6x_t");
extern const uint8_t u8g2_font_open_iconic_other_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_other_6x_t");
extern const uint8_t u8g2_font_open_iconic_play_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_play_6x_t");
extern const uint8_t u8g2_font_open_iconic_text_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_text_6x_t");
extern const uint8_t u8g2_font_open_iconic_thing_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_thing_6x_t");
extern const uint8_t u8g2_font_open_iconic_weather_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_weather_6x_t");
extern const uint8_t u8g2_font_open_iconic_www_6x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_www_6x_t");
extern const uint8_t u8g2_font_open_iconic_all_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_all_8x_t");
extern const uint8_t u8g2_font_open_iconic_app_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_app_8x_t");
extern const uint8_t u8g2_font_open_iconic_arrow_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_arrow_8x_t");
extern const uint8_t u8g2_font_open_iconic_check_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_check_8x_t");
extern const uint8_t u8g2_font_open_iconic_email_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_email_8x_t");
extern const uint8_t u8g2_font_open_iconic_embedded_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_embedded_8x_t");
extern const uint8_t u8g2_font_open_iconic_gui_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_gui_8x_t");
extern const uint8_t u8g2_font_open_iconic_human_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_human_8x_t");
extern const uint8_t u8g2_font_open_iconic_mime_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_mime_8x_t");
extern const uint8_t u8g2_font_open_iconic_other_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_other_8x_t");
extern const uint8_t u8g2_font_open_iconic_play_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_play_8x_t");
extern const uint8_t u8g2_font_open_iconic_text_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_text_8x_t");
extern const uint8_t u8g2_font_open_iconic_thing_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_thing_8x_t");
extern const uint8_t u8g2_font_open_iconic_weather_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_weather_8x_t");
extern const uint8_t u8g2_font_open_iconic_www_8x_t[] U8G2_FONT_SECTION("u8g2_font_open_iconic_www_8x_t");
extern const uint8_t u8g2_font_streamline_all_t[] U8G2_FONT_SECTION("u8g2_font_streamline_all_t");
extern const uint8_t u8g2_font_streamline_building_real_estate_t[] U8G2_FONT_SECTION("u8g2_font_streamline_building_real_estate_t");
extern const uint8_t u8g2_font_streamline_business_t[] U8G2_FONT_SECTION("u8g2_font_streamline_business_t");
extern const uint8_t u8g2_font_streamline_coding_apps_websites_t[] U8G2_FONT_SECTION("u8g2_font_streamline_coding_apps_websites_t");
extern const uint8_t u8g2_font_streamline_computers_devices_electronics_t[] U8G2_FONT_SECTION("u8g2_font_streamline_computers_devices_electronics_t");
extern const uint8_t u8g2_font_streamline_content_files_t[] U8G2_FONT_SECTION("u8g2_font_streamline_content_files_t");
extern const uint8_t u8g2_font_streamline_design_t[] U8G2_FONT_SECTION("u8g2_font_streamline_design_t");
extern const uint8_t u8g2_font_streamline_ecology_t[] U8G2_FONT_SECTION("u8g2_font_streamline_ecology_t");
extern const uint8_t u8g2_font_streamline_email_t[] U8G2_FONT_SECTION("u8g2_font_streamline_email_t");
extern const uint8_t u8g2_font_streamline_entertainment_events_hobbies_t[] U8G2_FONT_SECTION("u8g2_font_streamline_entertainment_events_hobbies_t");
extern const uint8_t u8g2_font_streamline_food_drink_t[] U8G2_FONT_SECTION("u8g2_font_streamline_food_drink_t");
extern const uint8_t u8g2_font_streamline_hand_signs_t[] U8G2_FONT_SECTION("u8g2_font_streamline_hand_signs_t");
extern const uint8_t u8g2_font_streamline_health_beauty_t[] U8G2_FONT_SECTION("u8g2_font_streamline_health_beauty_t");
extern const uint8_t u8g2_font_streamline_interface_essential_action_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_action_t");
extern const uint8_t u8g2_font_streamline_interface_essential_alert_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_alert_t");
extern const uint8_t u8g2_font_streamline_interface_essential_audio_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_audio_t");
extern const uint8_t u8g2_font_streamline_interface_essential_calendar_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_calendar_t");
extern const uint8_t u8g2_font_streamline_interface_essential_chart_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_chart_t");
extern const uint8_t u8g2_font_streamline_interface_essential_circle_triangle_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_circle_triangle_t");
extern const uint8_t u8g2_font_streamline_interface_essential_cog_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_cog_t");
extern const uint8_t u8g2_font_streamline_interface_essential_cursor_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_cursor_t");
extern const uint8_t u8g2_font_streamline_interface_essential_dial_pad_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_dial_pad_t");
extern const uint8_t u8g2_font_streamline_interface_essential_edit_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_edit_t");
extern const uint8_t u8g2_font_streamline_interface_essential_expand_shrink_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_expand_shrink_t");
extern const uint8_t u8g2_font_streamline_interface_essential_eye_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_eye_t");
extern const uint8_t u8g2_font_streamline_interface_essential_file_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_file_t");
extern const uint8_t u8g2_font_streamline_interface_essential_help_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_help_t");
extern const uint8_t u8g2_font_streamline_interface_essential_hierarchy_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_hierarchy_t");
extern const uint8_t u8g2_font_streamline_interface_essential_home_menu_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_home_menu_t");
extern const uint8_t u8g2_font_streamline_interface_essential_id_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_id_t");
extern const uint8_t u8g2_font_streamline_interface_essential_key_lock_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_key_lock_t");
extern const uint8_t u8g2_font_streamline_interface_essential_link_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_link_t");
extern const uint8_t u8g2_font_streamline_interface_essential_loading_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_loading_t");
extern const uint8_t u8g2_font_streamline_interface_essential_login_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_login_t");
extern const uint8_t u8g2_font_streamline_interface_essential_other_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_other_t");
extern const uint8_t u8g2_font_streamline_interface_essential_paginate_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_paginate_t");
extern const uint8_t u8g2_font_streamline_interface_essential_search_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_search_t");
extern const uint8_t u8g2_font_streamline_interface_essential_setting_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_setting_t");
extern const uint8_t u8g2_font_streamline_interface_essential_share_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_share_t");
extern const uint8_t u8g2_font_streamline_interface_essential_text_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_text_t");
extern const uint8_t u8g2_font_streamline_interface_essential_wifi_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_wifi_t");
extern const uint8_t u8g2_font_streamline_interface_essential_zoom_t[] U8G2_FONT_SECTION("u8g2_font_streamline_interface_essential_zoom_t");
extern const uint8_t u8g2_font_streamline_internet_network_t[] U8G2_FONT_SECTION("u8g2_font_streamline_internet_network_t");
extern const uint8_t u8g2_font_streamline_logo_t[] U8G2_FONT_SECTION("u8g2_font_streamline_logo_t");
extern const uint8_t u8g2_font_streamline_map_navigation_t[] U8G2_FONT_SECTION("u8g2_font_streamline_map_navigation_t");
extern const uint8_t u8g2_font_streamline_money_payments_t[] U8G2_FONT_SECTION("u8g2_font_streamline_money_payments_t");
extern const uint8_t u8g2_font_streamline_music_audio_t[] U8G2_FONT_SECTION("u8g2_font_streamline_music_audio_t");
extern const uint8_t u8g2_font_streamline_pet_animals_t[] U8G2_FONT_SECTION("u8g2_font_streamline_pet_animals_t");
extern const uint8_t u8g2_font_streamline_phone_t[] U8G2_FONT_SECTION("u8g2_font_streamline_phone_t");
extern const uint8_t u8g2_font_streamline_photography_t[] U8G2_FONT_SECTION("u8g2_font_streamline_photography_t");
extern const uint8_t u8g2_font_streamline_romance_t[] U8G2_FONT_SECTION("u8g2_font_streamline_romance_t");
extern const uint8_t u8g2_font_streamline_school_science_t[] U8G2_FONT_SECTION("u8g2_font_streamline_school_science_t");
extern const uint8_t u8g2_font_streamline_shopping_shipping_t[] U8G2_FONT_SECTION("u8g2_font_streamline_shopping_shipping_t");
extern const uint8_t u8g2_font_streamline_social_rewards_t[] U8G2_FONT_SECTION("u8g2_font_streamline_social_rewards_t");
extern const uint8_t u8g2_font_streamline_technology_t[] U8G2_FONT_SECTION("u8g2_font_streamline_technology_t");
extern const uint8_t u8g2_font_streamline_transportation_t[] U8G2_FONT_SECTION("u8g2_font_streamline_transportation_t");
extern const uint8_t u8g2_font_streamline_travel_wayfinding_t[] U8G2_FONT_SECTION("u8g2_font_streamline_travel_wayfinding_t");
extern const uint8_t u8g2_font_streamline_users_t[] U8G2_FONT_SECTION("u8g2_font_streamline_users_t");
extern const uint8_t u8g2_font_streamline_video_movies_t[] U8G2_FONT_SECTION("u8g2_font_streamline_video_movies_t");
extern const uint8_t u8g2_font_streamline_weather_t[] U8G2_FONT_SECTION("u8g2_font_streamline_weather_t");
extern const uint8_t u8g2_font_profont10_tf[] U8G2_FONT_SECTION("u8g2_font_profont10_tf");
extern const uint8_t u8g2_font_profont10_tr[] U8G2_FONT_SECTION("u8g2_font_profont10_tr");
extern const uint8_t u8g2_font_profont10_tn[] U8G2_FONT_SECTION("u8g2_font_profont10_tn");
extern const uint8_t u8g2_font_profont10_mf[] U8G2_FONT_SECTION("u8g2_font_profont10_mf");
extern const uint8_t u8g2_font_profont10_mr[] U8G2_FONT_SECTION("u8g2_font_profont10_mr");
extern const uint8_t u8g2_font_profont10_mn[] U8G2_FONT_SECTION("u8g2_font_profont10_mn");
extern const uint8_t u8g2_font_profont11_tf[] U8G2_FONT_SECTION("u8g2_font_profont11_tf");
extern const uint8_t u8g2_font_profont11_tr[] U8G2_FONT_SECTION("u8g2_font_profont11_tr");
extern const uint8_t u8g2_font_profont11_tn[] U8G2_FONT_SECTION("u8g2_font_profont11_tn");
extern const uint8_t u8g2_font_profont11_mf[] U8G2_FONT_SECTION("u8g2_font_profont11_mf");
extern const uint8_t u8g2_font_profont11_mr[] U8G2_FONT_SECTION("u8g2_font_profont11_mr");
extern const uint8_t u8g2_font_profont11_mn[] U8G2_FONT_SECTION("u8g2_font_profont11_mn");
extern const uint8_t u8g2_font_profont12_tf[] U8G2_FONT_SECTION("u8g2_font_profont12_tf");
extern const uint8_t u8g2_font_profont12_tr[] U8G2_FONT_SECTION("u8g2_font_profont12_tr");
extern const uint8_t u8g2_font_profont12_tn[] U8G2_FONT_SECTION("u8g2_font_profont12_tn");
extern const uint8_t u8g2_font_profont12_mf[] U8G2_FONT_SECTION("u8g2_font_profont12_mf");
extern const uint8_t u8g2_font_profont12_mr[] U8G2_FONT_SECTION("u8g2_font_profont12_mr");
extern const uint8_t u8g2_font_profont12_mn[] U8G2_FONT_SECTION("u8g2_font_profont12_mn");
extern const uint8_t u8g2_font_profont15_tf[] U8G2_FONT_SECTION("u8g2_font_profont15_tf");
extern const uint8_t u8g2_font_profont15_tr[] U8G2_FONT_SECTION("u8g2_font_profont15_tr");
extern const uint8_t u8g2_font_profont15_tn[] U8G2_FONT_SECTION("u8g2_font_profont15_tn");
extern const uint8_t u8g2_font_profont15_mf[] U8G2_FONT_SECTION("u8g2_font_profont15_mf");
extern const uint8_t u8g2_font_profont15_mr[] U8G2_FONT_SECTION("u8g2_font_profont15_mr");
extern const uint8_t u8g2_font_profont15_mn[] U8G2_FONT_SECTION("u8g2_font_profont15_mn");
extern const uint8_t u8g2_font_profont17_tf[] U8G2_FONT_SECTION("u8g2_font_profont17_tf");
extern const uint8_t u8g2_font_profont17_tr[] U8G2_FONT_SECTION("u8g2_font_profont17_tr");
extern const uint8_t u8g2_font_profont17_tn[] U8G2_FONT_SECTION("u8g2_font_profont17_tn");
extern const uint8_t u8g2_font_profont17_mf[] U8G2_FONT_SECTION("u8g2_font_profont17_mf");
extern const uint8_t u8g2_font_profont17_mr[] U8G2_FONT_SECTION("u8g2_font_profont17_mr");
extern const uint8_t u8g2_font_profont17_mn[] U8G2_FONT_SECTION("u8g2_font_profont17_mn");
extern const uint8_t u8g2_font_profont22_tf[] U8G2_FONT_SECTION("u8g2_font_profont22_tf");
extern const uint8_t u8g2_font_profont22_tr[] U8G2_FONT_SECTION("u8g2_font_profont22_tr");
extern const uint8_t u8g2_font_profont22_tn[] U8G2_FONT_SECTION("u8g2_font_profont22_tn");
extern const uint8_t u8g2_font_profont22_mf[] U8G2_FONT_SECTION("u8g2_font_profont22_mf");
extern const uint8_t u8g2_font_profont22_mr[] U8G2_FONT_SECTION("u8g2_font_profont22_mr");
extern const uint8_t u8g2_font_profont22_mn[] U8G2_FONT_SECTION("u8g2_font_profont22_mn");
extern const uint8_t u8g2_font_profont29_tf[] U8G2_FONT_SECTION("u8g2_font_profont29_tf");
extern const uint8_t u8g2_font_profont29_tr[] U8G2_FONT_SECTION("u8g2_font_profont29_tr");
extern const uint8_t u8g2_font_profont29_tn[] U8G2_FONT_SECTION("u8g2_font_profont29_tn");
extern const uint8_t u8g2_font_profont29_mf[] U8G2_FONT_SECTION("u8g2_font_profont29_mf");
extern const uint8_t u8g2_font_profont29_mr[] U8G2_FONT_SECTION("u8g2_font_profont29_mr");
extern const uint8_t u8g2_font_profont29_mn[] U8G2_FONT_SECTION("u8g2_font_profont29_mn");
extern const uint8_t u8g2_font_samim_10_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_10_t_all");
extern const uint8_t u8g2_font_samim_12_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_12_t_all");
extern const uint8_t u8g2_font_samim_14_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_14_t_all");
extern const uint8_t u8g2_font_samim_16_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_16_t_all");
extern const uint8_t u8g2_font_samim_fd_10_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_fd_10_t_all");
extern const uint8_t u8g2_font_samim_fd_12_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_fd_12_t_all");
extern const uint8_t u8g2_font_samim_fd_14_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_fd_14_t_all");
extern const uint8_t u8g2_font_samim_fd_16_t_all[] U8G2_FONT_SECTION("u8g2_font_samim_fd_16_t_all");
extern const uint8_t u8g2_font_ganj_nameh_sans10_t_all[] U8G2_FONT_SECTION("u8g2_font_ganj_nameh_sans10_t_all");
extern const uint8_t u8g2_font_ganj_nameh_sans12_t_all[] U8G2_FONT_SECTION("u8g2_font_ganj_nameh_sans12_t_all");
extern const uint8_t u8g2_font_ganj_nameh_sans14_t_all[] U8G2_FONT_SECTION("u8g2_font_ganj_nameh_sans14_t_all");
extern const uint8_t u8g2_font_ganj_nameh_sans16_t_all[] U8G2_FONT_SECTION("u8g2_font_ganj_nameh_sans16_t_all");
extern const uint8_t u8g2_font_iranian_sans_8_t_all[] U8G2_FONT_SECTION("u8g2_font_iranian_sans_8_t_all");
extern const uint8_t u8g2_font_iranian_sans_10_t_all[] U8G2_FONT_SECTION("u8g2_font_iranian_sans_10_t_all");
extern const uint8_t u8g2_font_iranian_sans_12_t_all[] U8G2_FONT_SECTION("u8g2_font_iranian_sans_12_t_all");
extern const uint8_t u8g2_font_iranian_sans_14_t_all[] U8G2_FONT_SECTION("u8g2_font_iranian_sans_14_t_all");
extern const uint8_t u8g2_font_iranian_sans_16_t_all[] U8G2_FONT_SECTION("u8g2_font_iranian_sans_16_t_all");
extern const uint8_t u8g2_font_mozart_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_mozart_nbp_tf");
extern const uint8_t u8g2_font_mozart_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_mozart_nbp_tr");
extern const uint8_t u8g2_font_mozart_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_mozart_nbp_tn");
extern const uint8_t u8g2_font_mozart_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_mozart_nbp_t_all");
extern const uint8_t u8g2_font_mozart_nbp_h_all[] U8G2_FONT_SECTION("u8g2_font_mozart_nbp_h_all");
extern const uint8_t u8g2_font_glasstown_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_glasstown_nbp_tf");
extern const uint8_t u8g2_font_glasstown_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_glasstown_nbp_tr");
extern const uint8_t u8g2_font_glasstown_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_glasstown_nbp_tn");
extern const uint8_t u8g2_font_glasstown_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_glasstown_nbp_t_all");
extern const uint8_t u8g2_font_shylock_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_shylock_nbp_tf");
extern const uint8_t u8g2_font_shylock_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_shylock_nbp_tr");
extern const uint8_t u8g2_font_shylock_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_shylock_nbp_tn");
extern const uint8_t u8g2_font_shylock_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_shylock_nbp_t_all");
extern const uint8_t u8g2_font_roentgen_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_roentgen_nbp_tf");
extern const uint8_t u8g2_font_roentgen_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_roentgen_nbp_tr");
extern const uint8_t u8g2_font_roentgen_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_roentgen_nbp_tn");
extern const uint8_t u8g2_font_roentgen_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_roentgen_nbp_t_all");
extern const uint8_t u8g2_font_roentgen_nbp_h_all[] U8G2_FONT_SECTION("u8g2_font_roentgen_nbp_h_all");
extern const uint8_t u8g2_font_calibration_gothic_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_calibration_gothic_nbp_tf");
extern const uint8_t u8g2_font_calibration_gothic_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_calibration_gothic_nbp_tr");
extern const uint8_t u8g2_font_calibration_gothic_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_calibration_gothic_nbp_tn");
extern const uint8_t u8g2_font_calibration_gothic_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_calibration_gothic_nbp_t_all");
extern const uint8_t u8g2_font_smart_patrol_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_smart_patrol_nbp_tf");
extern const uint8_t u8g2_font_smart_patrol_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_smart_patrol_nbp_tr");
extern const uint8_t u8g2_font_smart_patrol_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_smart_patrol_nbp_tn");
extern const uint8_t u8g2_font_prospero_bold_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_prospero_bold_nbp_tf");
extern const uint8_t u8g2_font_prospero_bold_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_prospero_bold_nbp_tr");
extern const uint8_t u8g2_font_prospero_bold_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_prospero_bold_nbp_tn");
extern const uint8_t u8g2_font_prospero_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_prospero_nbp_tf");
extern const uint8_t u8g2_font_prospero_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_prospero_nbp_tr");
extern const uint8_t u8g2_font_prospero_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_prospero_nbp_tn");
extern const uint8_t u8g2_font_balthasar_regular_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_balthasar_regular_nbp_tf");
extern const uint8_t u8g2_font_balthasar_regular_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_balthasar_regular_nbp_tr");
extern const uint8_t u8g2_font_balthasar_regular_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_balthasar_regular_nbp_tn");
extern const uint8_t u8g2_font_balthasar_titling_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_balthasar_titling_nbp_tf");
extern const uint8_t u8g2_font_balthasar_titling_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_balthasar_titling_nbp_tr");
extern const uint8_t u8g2_font_balthasar_titling_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_balthasar_titling_nbp_tn");
extern const uint8_t u8g2_font_synchronizer_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_synchronizer_nbp_tf");
extern const uint8_t u8g2_font_synchronizer_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_synchronizer_nbp_tr");
extern const uint8_t u8g2_font_synchronizer_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_synchronizer_nbp_tn");
extern const uint8_t u8g2_font_mercutio_basic_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_mercutio_basic_nbp_tf");
extern const uint8_t u8g2_font_mercutio_basic_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_mercutio_basic_nbp_tr");
extern const uint8_t u8g2_font_mercutio_basic_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_mercutio_basic_nbp_tn");
extern const uint8_t u8g2_font_mercutio_basic_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_mercutio_basic_nbp_t_all");
extern const uint8_t u8g2_font_mercutio_sc_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_mercutio_sc_nbp_tf");
extern const uint8_t u8g2_font_mercutio_sc_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_mercutio_sc_nbp_tr");
extern const uint8_t u8g2_font_mercutio_sc_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_mercutio_sc_nbp_tn");
extern const uint8_t u8g2_font_mercutio_sc_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_mercutio_sc_nbp_t_all");
extern const uint8_t u8g2_font_miranda_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_miranda_nbp_tf");
extern const uint8_t u8g2_font_miranda_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_miranda_nbp_tr");
extern const uint8_t u8g2_font_miranda_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_miranda_nbp_tn");
extern const uint8_t u8g2_font_nine_by_five_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_nine_by_five_nbp_tf");
extern const uint8_t u8g2_font_nine_by_five_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_nine_by_five_nbp_tr");
extern const uint8_t u8g2_font_nine_by_five_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_nine_by_five_nbp_tn");
extern const uint8_t u8g2_font_nine_by_five_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_nine_by_five_nbp_t_all");
extern const uint8_t u8g2_font_rosencrantz_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_rosencrantz_nbp_tf");
extern const uint8_t u8g2_font_rosencrantz_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_rosencrantz_nbp_tr");
extern const uint8_t u8g2_font_rosencrantz_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_rosencrantz_nbp_tn");
extern const uint8_t u8g2_font_rosencrantz_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_rosencrantz_nbp_t_all");
extern const uint8_t u8g2_font_guildenstern_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_guildenstern_nbp_tf");
extern const uint8_t u8g2_font_guildenstern_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_guildenstern_nbp_tr");
extern const uint8_t u8g2_font_guildenstern_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_guildenstern_nbp_tn");
extern const uint8_t u8g2_font_guildenstern_nbp_t_all[] U8G2_FONT_SECTION("u8g2_font_guildenstern_nbp_t_all");
extern const uint8_t u8g2_font_astragal_nbp_tf[] U8G2_FONT_SECTION("u8g2_font_astragal_nbp_tf");
extern const uint8_t u8g2_font_astragal_nbp_tr[] U8G2_FONT_SECTION("u8g2_font_astragal_nbp_tr");
extern const uint8_t u8g2_font_astragal_nbp_tn[] U8G2_FONT_SECTION("u8g2_font_astragal_nbp_tn");
extern const uint8_t u8g2_font_habsburgchancery_tf[] U8G2_FONT_SECTION("u8g2_font_habsburgchancery_tf");
extern const uint8_t u8g2_font_habsburgchancery_tr[] U8G2_FONT_SECTION("u8g2_font_habsburgchancery_tr");
extern const uint8_t u8g2_font_habsburgchancery_tn[] U8G2_FONT_SECTION("u8g2_font_habsburgchancery_tn");
extern const uint8_t u8g2_font_habsburgchancery_t_all[] U8G2_FONT_SECTION("u8g2_font_habsburgchancery_t_all");
extern const uint8_t u8g2_font_missingplanet_tf[] U8G2_FONT_SECTION("u8g2_font_missingplanet_tf");
extern const uint8_t u8g2_font_missingplanet_tr[] U8G2_FONT_SECTION("u8g2_font_missingplanet_tr");
extern const uint8_t u8g2_font_missingplanet_tn[] U8G2_FONT_SECTION("u8g2_font_missingplanet_tn");
extern const uint8_t u8g2_font_missingplanet_t_all[] U8G2_FONT_SECTION("u8g2_font_missingplanet_t_all");
extern const uint8_t u8g2_font_ordinarybasis_tf[] U8G2_FONT_SECTION("u8g2_font_ordinarybasis_tf");
extern const uint8_t u8g2_font_ordinarybasis_tr[] U8G2_FONT_SECTION("u8g2_font_ordinarybasis_tr");
extern const uint8_t u8g2_font_ordinarybasis_tn[] U8G2_FONT_SECTION("u8g2_font_ordinarybasis_tn");
extern const uint8_t u8g2_font_ordinarybasis_t_all[] U8G2_FONT_SECTION("u8g2_font_ordinarybasis_t_all");
extern const uint8_t u8g2_font_pixelmordred_tf[] U8G2_FONT_SECTION("u8g2_font_pixelmordred_tf");
extern const uint8_t u8g2_font_pixelmordred_tr[] U8G2_FONT_SECTION("u8g2_font_pixelmordred_tr");
extern const uint8_t u8g2_font_pixelmordred_tn[] U8G2_FONT_SECTION("u8g2_font_pixelmordred_tn");
extern const uint8_t u8g2_font_pixelmordred_t_all[] U8G2_FONT_SECTION("u8g2_font_pixelmordred_t_all");
extern const uint8_t u8g2_font_secretaryhand_tf[] U8G2_FONT_SECTION("u8g2_font_secretaryhand_tf");
extern const uint8_t u8g2_font_secretaryhand_tr[] U8G2_FONT_SECTION("u8g2_font_secretaryhand_tr");
extern const uint8_t u8g2_font_secretaryhand_tn[] U8G2_FONT_SECTION("u8g2_font_secretaryhand_tn");
extern const uint8_t u8g2_font_secretaryhand_t_all[] U8G2_FONT_SECTION("u8g2_font_secretaryhand_t_all");
extern const uint8_t u8g2_font_garbagecan_tf[] U8G2_FONT_SECTION("u8g2_font_garbagecan_tf");
extern const uint8_t u8g2_font_garbagecan_tr[] U8G2_FONT_SECTION("u8g2_font_garbagecan_tr");
extern const uint8_t u8g2_font_beanstalk_mel_tr[] U8G2_FONT_SECTION("u8g2_font_beanstalk_mel_tr");
extern const uint8_t u8g2_font_beanstalk_mel_tn[] U8G2_FONT_SECTION("u8g2_font_beanstalk_mel_tn");
extern const uint8_t u8g2_font_cube_mel_tr[] U8G2_FONT_SECTION("u8g2_font_cube_mel_tr");
extern const uint8_t u8g2_font_cube_mel_tn[] U8G2_FONT_SECTION("u8g2_font_cube_mel_tn");
extern const uint8_t u8g2_font_mademoiselle_mel_tr[] U8G2_FONT_SECTION("u8g2_font_mademoiselle_mel_tr");
extern const uint8_t u8g2_font_mademoiselle_mel_tn[] U8G2_FONT_SECTION("u8g2_font_mademoiselle_mel_tn");
extern const uint8_t u8g2_font_pieceofcake_mel_tr[] U8G2_FONT_SECTION("u8g2_font_pieceofcake_mel_tr");
extern const uint8_t u8g2_font_pieceofcake_mel_tn[] U8G2_FONT_SECTION("u8g2_font_pieceofcake_mel_tn");
extern const uint8_t u8g2_font_press_mel_tr[] U8G2_FONT_SECTION("u8g2_font_press_mel_tr");
extern const uint8_t u8g2_font_press_mel_tn[] U8G2_FONT_SECTION("u8g2_font_press_mel_tn");
extern const uint8_t u8g2_font_repress_mel_tr[] U8G2_FONT_SECTION("u8g2_font_repress_mel_tr");
extern const uint8_t u8g2_font_repress_mel_tn[] U8G2_FONT_SECTION("u8g2_font_repress_mel_tn");
extern const uint8_t u8g2_font_sticker_mel_tr[] U8G2_FONT_SECTION("u8g2_font_sticker_mel_tr");
extern const uint8_t u8g2_font_sticker_mel_tn[] U8G2_FONT_SECTION("u8g2_font_sticker_mel_tn");
extern const uint8_t u8g2_font_celibatemonk_tr[] U8G2_FONT_SECTION("u8g2_font_celibatemonk_tr");
extern const uint8_t u8g2_font_disrespectfulteenager_tu[] U8G2_FONT_SECTION("u8g2_font_disrespectfulteenager_tu");
extern const uint8_t u8g2_font_michaelmouse_tu[] U8G2_FONT_SECTION("u8g2_font_michaelmouse_tu");
extern const uint8_t u8g2_font_sandyforest_tr[] U8G2_FONT_SECTION("u8g2_font_sandyforest_tr");
extern const uint8_t u8g2_font_sandyforest_tn[] U8G2_FONT_SECTION("u8g2_font_sandyforest_tn");
extern const uint8_t u8g2_font_sandyforest_tu[] U8G2_FONT_SECTION("u8g2_font_sandyforest_tu");
extern const uint8_t u8g2_font_cupcakemetoyourleader_tr[] U8G2_FONT_SECTION("u8g2_font_cupcakemetoyourleader_tr");
extern const uint8_t u8g2_font_cupcakemetoyourleader_tn[] U8G2_FONT_SECTION("u8g2_font_cupcakemetoyourleader_tn");
extern const uint8_t u8g2_font_cupcakemetoyourleader_tu[] U8G2_FONT_SECTION("u8g2_font_cupcakemetoyourleader_tu");
extern const uint8_t u8g2_font_oldwizard_tf[] U8G2_FONT_SECTION("u8g2_font_oldwizard_tf");
extern const uint8_t u8g2_font_oldwizard_tr[] U8G2_FONT_SECTION("u8g2_font_oldwizard_tr");
extern const uint8_t u8g2_font_oldwizard_tn[] U8G2_FONT_SECTION("u8g2_font_oldwizard_tn");
extern const uint8_t u8g2_font_oldwizard_tu[] U8G2_FONT_SECTION("u8g2_font_oldwizard_tu");
extern const uint8_t u8g2_font_squirrel_tr[] U8G2_FONT_SECTION("u8g2_font_squirrel_tr");
extern const uint8_t u8g2_font_squirrel_tn[] U8G2_FONT_SECTION("u8g2_font_squirrel_tn");
extern const uint8_t u8g2_font_squirrel_tu[] U8G2_FONT_SECTION("u8g2_font_squirrel_tu");
extern const uint8_t u8g2_font_diodesemimono_tr[] U8G2_FONT_SECTION("u8g2_font_diodesemimono_tr");
extern const uint8_t u8g2_font_questgiver_tr[] U8G2_FONT_SECTION("u8g2_font_questgiver_tr");
extern const uint8_t u8g2_font_seraphimb1_tr[] U8G2_FONT_SECTION("u8g2_font_seraphimb1_tr");
extern const uint8_t u8g2_font_resoledbold_tr[] U8G2_FONT_SECTION("u8g2_font_resoledbold_tr");
extern const uint8_t u8g2_font_resoledmedium_tr[] U8G2_FONT_SECTION("u8g2_font_resoledmedium_tr");
extern const uint8_t u8g2_font_jinxedwizards_tr[] U8G2_FONT_SECTION("u8g2_font_jinxedwizards_tr");
extern const uint8_t u8g2_font_lastpriestess_tr[] U8G2_FONT_SECTION("u8g2_font_lastpriestess_tr");
extern const uint8_t u8g2_font_lastpriestess_tu[] U8G2_FONT_SECTION("u8g2_font_lastpriestess_tu");
extern const uint8_t u8g2_font_bitcasual_tf[] U8G2_FONT_SECTION("u8g2_font_bitcasual_tf");
extern const uint8_t u8g2_font_bitcasual_tr[] U8G2_FONT_SECTION("u8g2_font_bitcasual_tr");
extern const uint8_t u8g2_font_bitcasual_tn[] U8G2_FONT_SECTION("u8g2_font_bitcasual_tn");
extern const uint8_t u8g2_font_bitcasual_tu[] U8G2_FONT_SECTION("u8g2_font_bitcasual_tu");
extern const uint8_t u8g2_font_bitcasual_t_all[] U8G2_FONT_SECTION("u8g2_font_bitcasual_t_all");
extern const uint8_t u8g2_font_koleeko_tf[] U8G2_FONT_SECTION("u8g2_font_koleeko_tf");
extern const uint8_t u8g2_font_koleeko_tr[] U8G2_FONT_SECTION("u8g2_font_koleeko_tr");
extern const uint8_t u8g2_font_koleeko_tn[] U8G2_FONT_SECTION("u8g2_font_koleeko_tn");
extern const uint8_t u8g2_font_koleeko_tu[] U8G2_FONT_SECTION("u8g2_font_koleeko_tu");
extern const uint8_t u8g2_font_tenfatguys_tf[] U8G2_FONT_SECTION("u8g2_font_tenfatguys_tf");
extern const uint8_t u8g2_font_tenfatguys_tr[] U8G2_FONT_SECTION("u8g2_font_tenfatguys_tr");
extern const uint8_t u8g2_font_tenfatguys_tn[] U8G2_FONT_SECTION("u8g2_font_tenfatguys_tn");
extern const uint8_t u8g2_font_tenfatguys_tu[] U8G2_FONT_SECTION("u8g2_font_tenfatguys_tu");
extern const uint8_t u8g2_font_tenfatguys_t_all[] U8G2_FONT_SECTION("u8g2_font_tenfatguys_t_all");
extern const uint8_t u8g2_font_tenstamps_mf[] U8G2_FONT_SECTION("u8g2_font_tenstamps_mf");
extern const uint8_t u8g2_font_tenstamps_mr[] U8G2_FONT_SECTION("u8g2_font_tenstamps_mr");
extern const uint8_t u8g2_font_tenstamps_mn[] U8G2_FONT_SECTION("u8g2_font_tenstamps_mn");
extern const uint8_t u8g2_font_tenstamps_mu[] U8G2_FONT_SECTION("u8g2_font_tenstamps_mu");
extern const uint8_t u8g2_font_tenthinguys_tf[] U8G2_FONT_SECTION("u8g2_font_tenthinguys_tf");
extern const uint8_t u8g2_font_tenthinguys_tr[] U8G2_FONT_SECTION("u8g2_font_tenthinguys_tr");
extern const uint8_t u8g2_font_tenthinguys_tn[] U8G2_FONT_SECTION("u8g2_font_tenthinguys_tn");
extern const uint8_t u8g2_font_tenthinguys_tu[] U8G2_FONT_SECTION("u8g2_font_tenthinguys_tu");
extern const uint8_t u8g2_font_tenthinguys_t_all[] U8G2_FONT_SECTION("u8g2_font_tenthinguys_t_all");
extern const uint8_t u8g2_font_tenthinnerguys_tf[] U8G2_FONT_SECTION("u8g2_font_tenthinnerguys_tf");
extern const uint8_t u8g2_font_tenthinnerguys_tr[] U8G2_FONT_SECTION("u8g2_font_tenthinnerguys_tr");
extern const uint8_t u8g2_font_tenthinnerguys_tn[] U8G2_FONT_SECTION("u8g2_font_tenthinnerguys_tn");
extern const uint8_t u8g2_font_tenthinnerguys_tu[] U8G2_FONT_SECTION("u8g2_font_tenthinnerguys_tu");
extern const uint8_t u8g2_font_tenthinnerguys_t_all[] U8G2_FONT_SECTION("u8g2_font_tenthinnerguys_t_all");
extern const uint8_t u8g2_font_twelvedings_t_all[] U8G2_FONT_SECTION("u8g2_font_twelvedings_t_all");
extern const uint8_t u8g2_font_frigidaire_mr[] U8G2_FONT_SECTION("u8g2_font_frigidaire_mr");
extern const uint8_t u8g2_font_lord_mr[] U8G2_FONT_SECTION("u8g2_font_lord_mr");
extern const uint8_t u8g2_font_abel_mr[] U8G2_FONT_SECTION("u8g2_font_abel_mr");
extern const uint8_t u8g2_font_fewture_tf[] U8G2_FONT_SECTION("u8g2_font_fewture_tf");
extern const uint8_t u8g2_font_fewture_tr[] U8G2_FONT_SECTION("u8g2_font_fewture_tr");
extern const uint8_t u8g2_font_fewture_tn[] U8G2_FONT_SECTION("u8g2_font_fewture_tn");
extern const uint8_t u8g2_font_halftone_tf[] U8G2_FONT_SECTION("u8g2_font_halftone_tf");
extern const uint8_t u8g2_font_halftone_tr[] U8G2_FONT_SECTION("u8g2_font_halftone_tr");
extern const uint8_t u8g2_font_halftone_tn[] U8G2_FONT_SECTION("u8g2_font_halftone_tn");
extern const uint8_t u8g2_font_nerhoe_tf[] U8G2_FONT_SECTION("u8g2_font_nerhoe_tf");
extern const uint8_t u8g2_font_nerhoe_tr[] U8G2_FONT_SECTION("u8g2_font_nerhoe_tr");
extern const uint8_t u8g2_font_nerhoe_tn[] U8G2_FONT_SECTION("u8g2_font_nerhoe_tn");
extern const uint8_t u8g2_font_oskool_tf[] U8G2_FONT_SECTION("u8g2_font_oskool_tf");
extern const uint8_t u8g2_font_oskool_tr[] U8G2_FONT_SECTION("u8g2_font_oskool_tr");
extern const uint8_t u8g2_font_oskool_tn[] U8G2_FONT_SECTION("u8g2_font_oskool_tn");
extern const uint8_t u8g2_font_tinytim_tf[] U8G2_FONT_SECTION("u8g2_font_tinytim_tf");
extern const uint8_t u8g2_font_tinytim_tr[] U8G2_FONT_SECTION("u8g2_font_tinytim_tr");
extern const uint8_t u8g2_font_tinytim_tn[] U8G2_FONT_SECTION("u8g2_font_tinytim_tn");
extern const uint8_t u8g2_font_tooseornament_tf[] U8G2_FONT_SECTION("u8g2_font_tooseornament_tf");
extern const uint8_t u8g2_font_tooseornament_tr[] U8G2_FONT_SECTION("u8g2_font_tooseornament_tr");
extern const uint8_t u8g2_font_tooseornament_tn[] U8G2_FONT_SECTION("u8g2_font_tooseornament_tn");
extern const uint8_t u8g2_font_bauhaus2015_tr[] U8G2_FONT_SECTION("u8g2_font_bauhaus2015_tr");
extern const uint8_t u8g2_font_bauhaus2015_tn[] U8G2_FONT_SECTION("u8g2_font_bauhaus2015_tn");
extern const uint8_t u8g2_font_finderskeepers_tf[] U8G2_FONT_SECTION("u8g2_font_finderskeepers_tf");
extern const uint8_t u8g2_font_finderskeepers_tr[] U8G2_FONT_SECTION("u8g2_font_finderskeepers_tr");
extern const uint8_t u8g2_font_finderskeepers_tn[] U8G2_FONT_SECTION("u8g2_font_finderskeepers_tn");
extern const uint8_t u8g2_font_sirclivethebold_tr[] U8G2_FONT_SECTION("u8g2_font_sirclivethebold_tr");
extern const uint8_t u8g2_font_sirclivethebold_tn[] U8G2_FONT_SECTION("u8g2_font_sirclivethebold_tn");
extern const uint8_t u8g2_font_sirclive_tr[] U8G2_FONT_SECTION("u8g2_font_sirclive_tr");
extern const uint8_t u8g2_font_sirclive_tn[] U8G2_FONT_SECTION("u8g2_font_sirclive_tn");
extern const uint8_t u8g2_font_adventurer_tf[] U8G2_FONT_SECTION("u8g2_font_adventurer_tf");
extern const uint8_t u8g2_font_adventurer_tr[] U8G2_FONT_SECTION("u8g2_font_adventurer_tr");
extern const uint8_t u8g2_font_adventurer_t_all[] U8G2_FONT_SECTION("u8g2_font_adventurer_t_all");
extern const uint8_t u8g2_font_bracketedbabies_tr[] U8G2_FONT_SECTION("u8g2_font_bracketedbabies_tr");
extern const uint8_t u8g2_font_frikativ_tf[] U8G2_FONT_SECTION("u8g2_font_frikativ_tf");
extern const uint8_t u8g2_font_frikativ_tr[] U8G2_FONT_SECTION("u8g2_font_frikativ_tr");
extern const uint8_t u8g2_font_frikativ_t_all[] U8G2_FONT_SECTION("u8g2_font_frikativ_t_all");
extern const uint8_t u8g2_font_fancypixels_tf[] U8G2_FONT_SECTION("u8g2_font_fancypixels_tf");
extern const uint8_t u8g2_font_fancypixels_tr[] U8G2_FONT_SECTION("u8g2_font_fancypixels_tr");
extern const uint8_t u8g2_font_heavybottom_tr[] U8G2_FONT_SECTION("u8g2_font_heavybottom_tr");
extern const uint8_t u8g2_font_iconquadpix_m_all[] U8G2_FONT_SECTION("u8g2_font_iconquadpix_m_all");
extern const uint8_t u8g2_font_tallpix_tr[] U8G2_FONT_SECTION("u8g2_font_tallpix_tr");
extern const uint8_t u8g2_font_botmaker_te[] U8G2_FONT_SECTION("u8g2_font_botmaker_te");
extern const uint8_t u8g2_font_efraneextracondensed_te[] U8G2_FONT_SECTION("u8g2_font_efraneextracondensed_te");
extern const uint8_t u8g2_font_minimal3x3_tu[] U8G2_FONT_SECTION("u8g2_font_minimal3x3_tu");
extern const uint8_t u8g2_font_3x3basic_tr[] U8G2_FONT_SECTION("u8g2_font_3x3basic_tr");
extern const uint8_t u8g2_font_tiny_gk_tr[] U8G2_FONT_SECTION("u8g2_font_tiny_gk_tr");
extern const uint8_t u8g2_font_threepix_tr[] U8G2_FONT_SECTION("u8g2_font_threepix_tr");
extern const uint8_t u8g2_font_eventhrees_tr[] U8G2_FONT_SECTION("u8g2_font_eventhrees_tr");
extern const uint8_t u8g2_font_fourmat_tf[] U8G2_FONT_SECTION("u8g2_font_fourmat_tf");
extern const uint8_t u8g2_font_fourmat_tr[] U8G2_FONT_SECTION("u8g2_font_fourmat_tr");
extern const uint8_t u8g2_font_fourmat_te[] U8G2_FONT_SECTION("u8g2_font_fourmat_te");
extern const uint8_t u8g2_font_tiny_simon_tr[] U8G2_FONT_SECTION("u8g2_font_tiny_simon_tr");
extern const uint8_t u8g2_font_tiny_simon_mr[] U8G2_FONT_SECTION("u8g2_font_tiny_simon_mr");
extern const uint8_t u8g2_font_smolfont_tf[] U8G2_FONT_SECTION("u8g2_font_smolfont_tf");
extern const uint8_t u8g2_font_smolfont_tr[] U8G2_FONT_SECTION("u8g2_font_smolfont_tr");
extern const uint8_t u8g2_font_smolfont_te[] U8G2_FONT_SECTION("u8g2_font_smolfont_te");
extern const uint8_t u8g2_font_tinyunicode_tf[] U8G2_FONT_SECTION("u8g2_font_tinyunicode_tf");
extern const uint8_t u8g2_font_tinyunicode_tr[] U8G2_FONT_SECTION("u8g2_font_tinyunicode_tr");
extern const uint8_t u8g2_font_tinyunicode_te[] U8G2_FONT_SECTION("u8g2_font_tinyunicode_te");
extern const uint8_t u8g2_font_micropixel_tf[] U8G2_FONT_SECTION("u8g2_font_micropixel_tf");
extern const uint8_t u8g2_font_micropixel_tr[] U8G2_FONT_SECTION("u8g2_font_micropixel_tr");
extern const uint8_t u8g2_font_micropixel_te[] U8G2_FONT_SECTION("u8g2_font_micropixel_te");
extern const uint8_t u8g2_font_tinypixie2_tr[] U8G2_FONT_SECTION("u8g2_font_tinypixie2_tr");
extern const uint8_t u8g2_font_standardized3x5_tr[] U8G2_FONT_SECTION("u8g2_font_standardized3x5_tr");
extern const uint8_t u8g2_font_fivepx_tr[] U8G2_FONT_SECTION("u8g2_font_fivepx_tr");
extern const uint8_t u8g2_font_3x5im_tr[] U8G2_FONT_SECTION("u8g2_font_3x5im_tr");
extern const uint8_t u8g2_font_3x5im_te[] U8G2_FONT_SECTION("u8g2_font_3x5im_te");
extern const uint8_t u8g2_font_3x5im_mr[] U8G2_FONT_SECTION("u8g2_font_3x5im_mr");
extern const uint8_t u8g2_font_wedge_tr[] U8G2_FONT_SECTION("u8g2_font_wedge_tr");
extern const uint8_t u8g2_font_kibibyte_tr[] U8G2_FONT_SECTION("u8g2_font_kibibyte_tr");
extern const uint8_t u8g2_font_kibibyte_te[] U8G2_FONT_SECTION("u8g2_font_kibibyte_te");
extern const uint8_t u8g2_font_tinyface_tr[] U8G2_FONT_SECTION("u8g2_font_tinyface_tr");
extern const uint8_t u8g2_font_tinyface_te[] U8G2_FONT_SECTION("u8g2_font_tinyface_te");
extern const uint8_t u8g2_font_smallsimple_tr[] U8G2_FONT_SECTION("u8g2_font_smallsimple_tr");
extern const uint8_t u8g2_font_smallsimple_te[] U8G2_FONT_SECTION("u8g2_font_smallsimple_te");
extern const uint8_t u8g2_font_simple1_tf[] U8G2_FONT_SECTION("u8g2_font_simple1_tf");
extern const uint8_t u8g2_font_simple1_tr[] U8G2_FONT_SECTION("u8g2_font_simple1_tr");
extern const uint8_t u8g2_font_simple1_te[] U8G2_FONT_SECTION("u8g2_font_simple1_te");
extern const uint8_t u8g2_font_likeminecraft_te[] U8G2_FONT_SECTION("u8g2_font_likeminecraft_te");
extern const uint8_t u8g2_font_medsans_tr[] U8G2_FONT_SECTION("u8g2_font_medsans_tr");
extern const uint8_t u8g2_font_heisans_tr[] U8G2_FONT_SECTION("u8g2_font_heisans_tr");
extern const uint8_t u8g2_font_originalsans_tr[] U8G2_FONT_SECTION("u8g2_font_originalsans_tr");
extern const uint8_t u8g2_font_minicute_tr[] U8G2_FONT_SECTION("u8g2_font_minicute_tr");
extern const uint8_t u8g2_font_minicute_te[] U8G2_FONT_SECTION("u8g2_font_minicute_te");
extern const uint8_t u8g2_font_scrum_tf[] U8G2_FONT_SECTION("u8g2_font_scrum_tf");
extern const uint8_t u8g2_font_scrum_tr[] U8G2_FONT_SECTION("u8g2_font_scrum_tr");
extern const uint8_t u8g2_font_scrum_te[] U8G2_FONT_SECTION("u8g2_font_scrum_te");
extern const uint8_t u8g2_font_stylishcharm_tr[] U8G2_FONT_SECTION("u8g2_font_stylishcharm_tr");
extern const uint8_t u8g2_font_stylishcharm_te[] U8G2_FONT_SECTION("u8g2_font_stylishcharm_te");
extern const uint8_t u8g2_font_sisterserif_tr[] U8G2_FONT_SECTION("u8g2_font_sisterserif_tr");
extern const uint8_t u8g2_font_princess_tr[] U8G2_FONT_SECTION("u8g2_font_princess_tr");
extern const uint8_t u8g2_font_princess_te[] U8G2_FONT_SECTION("u8g2_font_princess_te");
extern const uint8_t u8g2_font_dystopia_tr[] U8G2_FONT_SECTION("u8g2_font_dystopia_tr");
extern const uint8_t u8g2_font_dystopia_te[] U8G2_FONT_SECTION("u8g2_font_dystopia_te");
extern const uint8_t u8g2_font_lastapprenticethin_tr[] U8G2_FONT_SECTION("u8g2_font_lastapprenticethin_tr");
extern const uint8_t u8g2_font_lastapprenticethin_te[] U8G2_FONT_SECTION("u8g2_font_lastapprenticethin_te");
extern const uint8_t u8g2_font_lastapprenticebold_tr[] U8G2_FONT_SECTION("u8g2_font_lastapprenticebold_tr");
extern const uint8_t u8g2_font_lastapprenticebold_te[] U8G2_FONT_SECTION("u8g2_font_lastapprenticebold_te");
extern const uint8_t u8g2_font_bpixel_tr[] U8G2_FONT_SECTION("u8g2_font_bpixel_tr");
extern const uint8_t u8g2_font_bpixel_te[] U8G2_FONT_SECTION("u8g2_font_bpixel_te");
extern const uint8_t u8g2_font_bpixeldouble_tr[] U8G2_FONT_SECTION("u8g2_font_bpixeldouble_tr");
extern const uint8_t u8g2_font_mildras_tr[] U8G2_FONT_SECTION("u8g2_font_mildras_tr");
extern const uint8_t u8g2_font_mildras_te[] U8G2_FONT_SECTION("u8g2_font_mildras_te");
extern const uint8_t u8g2_font_minuteconsole_mr[] U8G2_FONT_SECTION("u8g2_font_minuteconsole_mr");
extern const uint8_t u8g2_font_minuteconsole_tr[] U8G2_FONT_SECTION("u8g2_font_minuteconsole_tr");
extern const uint8_t u8g2_font_busdisplay11x5_tr[] U8G2_FONT_SECTION("u8g2_font_busdisplay11x5_tr");
extern const uint8_t u8g2_font_busdisplay11x5_te[] U8G2_FONT_SECTION("u8g2_font_busdisplay11x5_te");
extern const uint8_t u8g2_font_busdisplay8x5_tr[] U8G2_FONT_SECTION("u8g2_font_busdisplay8x5_tr");
extern const uint8_t u8g2_font_sticker100complete_tr[] U8G2_FONT_SECTION("u8g2_font_sticker100complete_tr");
extern const uint8_t u8g2_font_sticker100complete_te[] U8G2_FONT_SECTION("u8g2_font_sticker100complete_te");
extern const uint8_t u8g2_font_doomalpha04_tr[] U8G2_FONT_SECTION("u8g2_font_doomalpha04_tr");
extern const uint8_t u8g2_font_doomalpha04_te[] U8G2_FONT_SECTION("u8g2_font_doomalpha04_te");
extern const uint8_t u8g2_font_greenbloodserif2_tr[] U8G2_FONT_SECTION("u8g2_font_greenbloodserif2_tr");
extern const uint8_t u8g2_font_eckpixel_tr[] U8G2_FONT_SECTION("u8g2_font_eckpixel_tr");
extern const uint8_t u8g2_font_elispe_tr[] U8G2_FONT_SECTION("u8g2_font_elispe_tr");
extern const uint8_t u8g2_font_neuecraft_tr[] U8G2_FONT_SECTION("u8g2_font_neuecraft_tr");
extern const uint8_t u8g2_font_neuecraft_te[] U8G2_FONT_SECTION("u8g2_font_neuecraft_te");
extern const uint8_t u8g2_font_8bitclassic_tf[] U8G2_FONT_SECTION("u8g2_font_8bitclassic_tf");
extern const uint8_t u8g2_font_8bitclassic_tr[] U8G2_FONT_SECTION("u8g2_font_8bitclassic_tr");
extern const uint8_t u8g2_font_8bitclassic_te[] U8G2_FONT_SECTION("u8g2_font_8bitclassic_te");
extern const uint8_t u8g2_font_littlemissloudonbold_tr[] U8G2_FONT_SECTION("u8g2_font_littlemissloudonbold_tr");
extern const uint8_t u8g2_font_littlemissloudonbold_te[] U8G2_FONT_SECTION("u8g2_font_littlemissloudonbold_te");
extern const uint8_t u8g2_font_commodore64_tr[] U8G2_FONT_SECTION("u8g2_font_commodore64_tr");
extern const uint8_t u8g2_font_new3x9pixelfont_tf[] U8G2_FONT_SECTION("u8g2_font_new3x9pixelfont_tf");
extern const uint8_t u8g2_font_new3x9pixelfont_tr[] U8G2_FONT_SECTION("u8g2_font_new3x9pixelfont_tr");
extern const uint8_t u8g2_font_new3x9pixelfont_te[] U8G2_FONT_SECTION("u8g2_font_new3x9pixelfont_te");
extern const uint8_t u8g2_font_sonicmania_tr[] U8G2_FONT_SECTION("u8g2_font_sonicmania_tr");
extern const uint8_t u8g2_font_sonicmania_te[] U8G2_FONT_SECTION("u8g2_font_sonicmania_te");
extern const uint8_t u8g2_font_bytesize_tf[] U8G2_FONT_SECTION("u8g2_font_bytesize_tf");
extern const uint8_t u8g2_font_bytesize_tr[] U8G2_FONT_SECTION("u8g2_font_bytesize_tr");
extern const uint8_t u8g2_font_bytesize_te[] U8G2_FONT_SECTION("u8g2_font_bytesize_te");
extern const uint8_t u8g2_font_pixzillav1_tf[] U8G2_FONT_SECTION("u8g2_font_pixzillav1_tf");
extern const uint8_t u8g2_font_pixzillav1_tr[] U8G2_FONT_SECTION("u8g2_font_pixzillav1_tr");
extern const uint8_t u8g2_font_pixzillav1_te[] U8G2_FONT_SECTION("u8g2_font_pixzillav1_te");
extern const uint8_t u8g2_font_ciircle13_tr[] U8G2_FONT_SECTION("u8g2_font_ciircle13_tr");
extern const uint8_t u8g2_font_pxclassic_tf[] U8G2_FONT_SECTION("u8g2_font_pxclassic_tf");
extern const uint8_t u8g2_font_pxclassic_tr[] U8G2_FONT_SECTION("u8g2_font_pxclassic_tr");
extern const uint8_t u8g2_font_pxclassic_te[] U8G2_FONT_SECTION("u8g2_font_pxclassic_te");
extern const uint8_t u8g2_font_moosenooks_tr[] U8G2_FONT_SECTION("u8g2_font_moosenooks_tr");
extern const uint8_t u8g2_font_tallpixelextended_tf[] U8G2_FONT_SECTION("u8g2_font_tallpixelextended_tf");
extern const uint8_t u8g2_font_tallpixelextended_tr[] U8G2_FONT_SECTION("u8g2_font_tallpixelextended_tr");
extern const uint8_t u8g2_font_tallpixelextended_te[] U8G2_FONT_SECTION("u8g2_font_tallpixelextended_te");
extern const uint8_t u8g2_font_BBSesque_tf[] U8G2_FONT_SECTION("u8g2_font_BBSesque_tf");
extern const uint8_t u8g2_font_BBSesque_tr[] U8G2_FONT_SECTION("u8g2_font_BBSesque_tr");
extern const uint8_t u8g2_font_BBSesque_te[] U8G2_FONT_SECTION("u8g2_font_BBSesque_te");
extern const uint8_t u8g2_font_Born2bSportySlab_tf[] U8G2_FONT_SECTION("u8g2_font_Born2bSportySlab_tf");
extern const uint8_t u8g2_font_Born2bSportySlab_tr[] U8G2_FONT_SECTION("u8g2_font_Born2bSportySlab_tr");
extern const uint8_t u8g2_font_Born2bSportySlab_te[] U8G2_FONT_SECTION("u8g2_font_Born2bSportySlab_te");
extern const uint8_t u8g2_font_Born2bSportySlab_t_all[] U8G2_FONT_SECTION("u8g2_font_Born2bSportySlab_t_all");
extern const uint8_t u8g2_font_Born2bSportyV2_tf[] U8G2_FONT_SECTION("u8g2_font_Born2bSportyV2_tf");
extern const uint8_t u8g2_font_Born2bSportyV2_tr[] U8G2_FONT_SECTION("u8g2_font_Born2bSportyV2_tr");
extern const uint8_t u8g2_font_Born2bSportyV2_te[] U8G2_FONT_SECTION("u8g2_font_Born2bSportyV2_te");
extern const uint8_t u8g2_font_CursivePixel_tr[] U8G2_FONT_SECTION("u8g2_font_CursivePixel_tr");
extern const uint8_t u8g2_font_Engrish_tf[] U8G2_FONT_SECTION("u8g2_font_Engrish_tf");
extern const uint8_t u8g2_font_Engrish_tr[] U8G2_FONT_SECTION("u8g2_font_Engrish_tr");
extern const uint8_t u8g2_font_ImpactBits_tr[] U8G2_FONT_SECTION("u8g2_font_ImpactBits_tr");
extern const uint8_t u8g2_font_IPAandRUSLCD_tf[] U8G2_FONT_SECTION("u8g2_font_IPAandRUSLCD_tf");
extern const uint8_t u8g2_font_IPAandRUSLCD_tr[] U8G2_FONT_SECTION("u8g2_font_IPAandRUSLCD_tr");
extern const uint8_t u8g2_font_IPAandRUSLCD_te[] U8G2_FONT_SECTION("u8g2_font_IPAandRUSLCD_te");
extern const uint8_t u8g2_font_PixelTheatre_tr[] U8G2_FONT_SECTION("u8g2_font_PixelTheatre_tr");
extern const uint8_t u8g2_font_PixelTheatre_te[] U8G2_FONT_SECTION("u8g2_font_PixelTheatre_te");
extern const uint8_t u8g2_font_HelvetiPixel_tr[] U8G2_FONT_SECTION("u8g2_font_HelvetiPixel_tr");
extern const uint8_t u8g2_font_TimesNewPixel_tr[] U8G2_FONT_SECTION("u8g2_font_TimesNewPixel_tr");
extern const uint8_t u8g2_font_BitTypeWriter_tr[] U8G2_FONT_SECTION("u8g2_font_BitTypeWriter_tr");
extern const uint8_t u8g2_font_BitTypeWriter_te[] U8G2_FONT_SECTION("u8g2_font_BitTypeWriter_te");
extern const uint8_t u8g2_font_Georgia7px_tf[] U8G2_FONT_SECTION("u8g2_font_Georgia7px_tf");
extern const uint8_t u8g2_font_Georgia7px_tr[] U8G2_FONT_SECTION("u8g2_font_Georgia7px_tr");
extern const uint8_t u8g2_font_Georgia7px_te[] U8G2_FONT_SECTION("u8g2_font_Georgia7px_te");
extern const uint8_t u8g2_font_Wizzard_tr[] U8G2_FONT_SECTION("u8g2_font_Wizzard_tr");
extern const uint8_t u8g2_font_HelvetiPixelOutline_tr[] U8G2_FONT_SECTION("u8g2_font_HelvetiPixelOutline_tr");
extern const uint8_t u8g2_font_HelvetiPixelOutline_te[] U8G2_FONT_SECTION("u8g2_font_HelvetiPixelOutline_te");
extern const uint8_t u8g2_font_Untitled16PixelSansSerifBitmap_tr[] U8G2_FONT_SECTION("u8g2_font_Untitled16PixelSansSerifBitmap_tr");
extern const uint8_t u8g2_font_UnnamedDOSFontIV_tr[] U8G2_FONT_SECTION("u8g2_font_UnnamedDOSFontIV_tr");
extern const uint8_t u8g2_font_Terminal_tr[] U8G2_FONT_SECTION("u8g2_font_Terminal_tr");
extern const uint8_t u8g2_font_Terminal_te[] U8G2_FONT_SECTION("u8g2_font_Terminal_te");
extern const uint8_t u8g2_font_NokiaLargeBold_tf[] U8G2_FONT_SECTION("u8g2_font_NokiaLargeBold_tf");
extern const uint8_t u8g2_font_NokiaLargeBold_tr[] U8G2_FONT_SECTION("u8g2_font_NokiaLargeBold_tr");
extern const uint8_t u8g2_font_NokiaLargeBold_te[] U8G2_FONT_SECTION("u8g2_font_NokiaLargeBold_te");
extern const uint8_t u8g2_font_NokiaSmallBold_tf[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallBold_tf");
extern const uint8_t u8g2_font_NokiaSmallBold_tr[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallBold_tr");
extern const uint8_t u8g2_font_NokiaSmallBold_te[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallBold_te");
extern const uint8_t u8g2_font_NokiaSmallPlain_tf[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallPlain_tf");
extern const uint8_t u8g2_font_NokiaSmallPlain_tr[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallPlain_tr");
extern const uint8_t u8g2_font_NokiaSmallPlain_te[] U8G2_FONT_SECTION("u8g2_font_NokiaSmallPlain_te");
extern const uint8_t u8g2_font_12x6LED_tf[] U8G2_FONT_SECTION("u8g2_font_12x6LED_tf");
extern const uint8_t u8g2_font_12x6LED_tr[] U8G2_FONT_SECTION("u8g2_font_12x6LED_tr");
extern const uint8_t u8g2_font_12x6LED_mn[] U8G2_FONT_SECTION("u8g2_font_12x6LED_mn");
extern const uint8_t u8g2_font_9x6LED_tf[] U8G2_FONT_SECTION("u8g2_font_9x6LED_tf");
extern const uint8_t u8g2_font_9x6LED_tr[] U8G2_FONT_SECTION("u8g2_font_9x6LED_tr");
extern const uint8_t u8g2_font_9x6LED_mn[] U8G2_FONT_SECTION("u8g2_font_9x6LED_mn");
extern const uint8_t u8g2_font_calblk36_tr[] U8G2_FONT_SECTION("u8g2_font_calblk36_tr");
extern const uint8_t u8g2_font_callite24_tr[] U8G2_FONT_SECTION("u8g2_font_callite24_tr");
extern const uint8_t u8g2_font_spleen5x8_mf[] U8G2_FONT_SECTION("u8g2_font_spleen5x8_mf");
extern const uint8_t u8g2_font_spleen5x8_mr[] U8G2_FONT_SECTION("u8g2_font_spleen5x8_mr");
extern const uint8_t u8g2_font_spleen5x8_mn[] U8G2_FONT_SECTION("u8g2_font_spleen5x8_mn");
extern const uint8_t u8g2_font_spleen5x8_mu[] U8G2_FONT_SECTION("u8g2_font_spleen5x8_mu");
extern const uint8_t u8g2_font_spleen5x8_me[] U8G2_FONT_SECTION("u8g2_font_spleen5x8_me");
extern const uint8_t u8g2_font_spleen6x12_mf[] U8G2_FONT_SECTION("u8g2_font_spleen6x12_mf");
extern const uint8_t u8g2_font_spleen6x12_mr[] U8G2_FONT_SECTION("u8g2_font_spleen6x12_mr");
extern const uint8_t u8g2_font_spleen6x12_mn[] U8G2_FONT_SECTION("u8g2_font_spleen6x12_mn");
extern const uint8_t u8g2_font_spleen6x12_mu[] U8G2_FONT_SECTION("u8g2_font_spleen6x12_mu");
extern const uint8_t u8g2_font_spleen6x12_me[] U8G2_FONT_SECTION("u8g2_font_spleen6x12_me");
extern const uint8_t u8g2_font_spleen8x16_mf[] U8G2_FONT_SECTION("u8g2_font_spleen8x16_mf");
extern const uint8_t u8g2_font_spleen8x16_mr[] U8G2_FONT_SECTION("u8g2_font_spleen8x16_mr");
extern const uint8_t u8g2_font_spleen8x16_mn[] U8G2_FONT_SECTION("u8g2_font_spleen8x16_mn");
extern const uint8_t u8g2_font_spleen8x16_mu[] U8G2_FONT_SECTION("u8g2_font_spleen8x16_mu");
extern const uint8_t u8g2_font_spleen8x16_me[] U8G2_FONT_SECTION("u8g2_font_spleen8x16_me");
extern const uint8_t u8g2_font_spleen12x24_mf[] U8G2_FONT_SECTION("u8g2_font_spleen12x24_mf");
extern const uint8_t u8g2_font_spleen12x24_mr[] U8G2_FONT_SECTION("u8g2_font_spleen12x24_mr");
extern const uint8_t u8g2_font_spleen12x24_mn[] U8G2_FONT_SECTION("u8g2_font_spleen12x24_mn");
extern const uint8_t u8g2_font_spleen12x24_mu[] U8G2_FONT_SECTION("u8g2_font_spleen12x24_mu");
extern const uint8_t u8g2_font_spleen12x24_me[] U8G2_FONT_SECTION("u8g2_font_spleen12x24_me");
extern const uint8_t u8g2_font_spleen16x32_mf[] U8G2_FONT_SECTION("u8g2_font_spleen16x32_mf");
extern const uint8_t u8g2_font_spleen16x32_mr[] U8G2_FONT_SECTION("u8g2_font_spleen16x32_mr");
extern const uint8_t u8g2_font_spleen16x32_mn[] U8G2_FONT_SECTION("u8g2_font_spleen16x32_mn");
extern const uint8_t u8g2_font_spleen16x32_mu[] U8G2_FONT_SECTION("u8g2_font_spleen16x32_mu");
extern const uint8_t u8g2_font_spleen16x32_me[] U8G2_FONT_SECTION("u8g2_font_spleen16x32_me");
extern const uint8_t u8g2_font_spleen32x64_mf[] U8G2_FONT_SECTION("u8g2_font_spleen32x64_mf");
extern const uint8_t u8g2_font_spleen32x64_mr[] U8G2_FONT_SECTION("u8g2_font_spleen32x64_mr");
extern const uint8_t u8g2_font_spleen32x64_mn[] U8G2_FONT_SECTION("u8g2_font_spleen32x64_mn");
extern const uint8_t u8g2_font_spleen32x64_mu[] U8G2_FONT_SECTION("u8g2_font_spleen32x64_mu");
extern const uint8_t u8g2_font_spleen32x64_me[] U8G2_FONT_SECTION("u8g2_font_spleen32x64_me");
extern const uint8_t u8g2_font_nokiafc22_tf[] U8G2_FONT_SECTION("u8g2_font_nokiafc22_tf");
extern const uint8_t u8g2_font_nokiafc22_tr[] U8G2_FONT_SECTION("u8g2_font_nokiafc22_tr");
extern const uint8_t u8g2_font_nokiafc22_tn[] U8G2_FONT_SECTION("u8g2_font_nokiafc22_tn");
extern const uint8_t u8g2_font_nokiafc22_tu[] U8G2_FONT_SECTION("u8g2_font_nokiafc22_tu");
extern const uint8_t u8g2_font_VCR_OSD_tf[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_tf");
extern const uint8_t u8g2_font_VCR_OSD_tr[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_tr");
extern const uint8_t u8g2_font_VCR_OSD_tn[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_tn");
extern const uint8_t u8g2_font_VCR_OSD_tu[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_tu");
extern const uint8_t u8g2_font_VCR_OSD_mf[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_mf");
extern const uint8_t u8g2_font_VCR_OSD_mr[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_mr");
extern const uint8_t u8g2_font_VCR_OSD_mn[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_mn");
extern const uint8_t u8g2_font_VCR_OSD_mu[] U8G2_FONT_SECTION("u8g2_font_VCR_OSD_mu");
extern const uint8_t u8g2_font_Pixellari_tf[] U8G2_FONT_SECTION("u8g2_font_Pixellari_tf");
extern const uint8_t u8g2_font_Pixellari_tr[] U8G2_FONT_SECTION("u8g2_font_Pixellari_tr");
extern const uint8_t u8g2_font_Pixellari_tn[] U8G2_FONT_SECTION("u8g2_font_Pixellari_tn");
extern const uint8_t u8g2_font_Pixellari_tu[] U8G2_FONT_SECTION("u8g2_font_Pixellari_tu");
extern const uint8_t u8g2_font_Pixellari_te[] U8G2_FONT_SECTION("u8g2_font_Pixellari_te");
extern const uint8_t u8g2_font_pixelpoiiz_tr[] U8G2_FONT_SECTION("u8g2_font_pixelpoiiz_tr");
extern const uint8_t u8g2_font_DigitalDiscoThin_tf[] U8G2_FONT_SECTION("u8g2_font_DigitalDiscoThin_tf");
extern const uint8_t u8g2_font_DigitalDiscoThin_tr[] U8G2_FONT_SECTION("u8g2_font_DigitalDiscoThin_tr");
extern const uint8_t u8g2_font_DigitalDiscoThin_tn[] U8G2_FONT_SECTION("u8g2_font_DigitalDiscoThin_tn");
extern const uint8_t u8g2_font_DigitalDiscoThin_tu[] U8G2_FONT_SECTION("u8g2_font_DigitalDiscoThin_tu");
extern const uint8_t u8g2_font_DigitalDiscoThin_te[] U8G2_FONT_SECTION("u8g2_font_DigitalDiscoThin_te");
extern const uint8_t u8g2_font_DigitalDisco_tf[] U8G2_FONT_SECTION("u8g2_font_DigitalDisco_tf");
extern const uint8_t u8g2_font_DigitalDisco_tr[] U8G2_FONT_SECTION("u8g2_font_DigitalDisco_tr");
extern const uint8_t u8g2_font_DigitalDisco_tn[] U8G2_FONT_SECTION("u8g2_font_DigitalDisco_tn");
extern const uint8_t u8g2_font_DigitalDisco_tu[] U8G2_FONT_SECTION("u8g2_font_DigitalDisco_tu");
extern const uint8_t u8g2_font_DigitalDisco_te[] U8G2_FONT_SECTION("u8g2_font_DigitalDisco_te");
extern const uint8_t u8g2_font_pearfont_tr[] U8G2_FONT_SECTION("u8g2_font_pearfont_tr");
extern const uint8_t u8g2_font_etl14thai_t[] U8G2_FONT_SECTION("u8g2_font_etl14thai_t");
extern const uint8_t u8g2_font_etl16thai_t[] U8G2_FONT_SECTION("u8g2_font_etl16thai_t");
extern const uint8_t u8g2_font_etl24thai_t[] U8G2_FONT_SECTION("u8g2_font_etl24thai_t");
extern const uint8_t u8g2_font_crox1cb_tf[] U8G2_FONT_SECTION("u8g2_font_crox1cb_tf");
extern const uint8_t u8g2_font_crox1cb_tr[] U8G2_FONT_SECTION("u8g2_font_crox1cb_tr");
extern const uint8_t u8g2_font_crox1cb_tn[] U8G2_FONT_SECTION("u8g2_font_crox1cb_tn");
extern const uint8_t u8g2_font_crox1cb_mf[] U8G2_FONT_SECTION("u8g2_font_crox1cb_mf");
extern const uint8_t u8g2_font_crox1cb_mr[] U8G2_FONT_SECTION("u8g2_font_crox1cb_mr");
extern const uint8_t u8g2_font_crox1cb_mn[] U8G2_FONT_SECTION("u8g2_font_crox1cb_mn");
extern const uint8_t u8g2_font_crox1c_tf[] U8G2_FONT_SECTION("u8g2_font_crox1c_tf");
extern const uint8_t u8g2_font_crox1c_tr[] U8G2_FONT_SECTION("u8g2_font_crox1c_tr");
extern const uint8_t u8g2_font_crox1c_tn[] U8G2_FONT_SECTION("u8g2_font_crox1c_tn");
extern const uint8_t u8g2_font_crox1c_mf[] U8G2_FONT_SECTION("u8g2_font_crox1c_mf");
extern const uint8_t u8g2_font_crox1c_mr[] U8G2_FONT_SECTION("u8g2_font_crox1c_mr");
extern const uint8_t u8g2_font_crox1c_mn[] U8G2_FONT_SECTION("u8g2_font_crox1c_mn");
extern const uint8_t u8g2_font_crox1hb_tf[] U8G2_FONT_SECTION("u8g2_font_crox1hb_tf");
extern const uint8_t u8g2_font_crox1hb_tr[] U8G2_FONT_SECTION("u8g2_font_crox1hb_tr");
extern const uint8_t u8g2_font_crox1hb_tn[] U8G2_FONT_SECTION("u8g2_font_crox1hb_tn");
extern const uint8_t u8g2_font_crox1h_tf[] U8G2_FONT_SECTION("u8g2_font_crox1h_tf");
extern const uint8_t u8g2_font_crox1h_tr[] U8G2_FONT_SECTION("u8g2_font_crox1h_tr");
extern const uint8_t u8g2_font_crox1h_tn[] U8G2_FONT_SECTION("u8g2_font_crox1h_tn");
extern const uint8_t u8g2_font_crox1tb_tf[] U8G2_FONT_SECTION("u8g2_font_crox1tb_tf");
extern const uint8_t u8g2_font_crox1tb_tr[] U8G2_FONT_SECTION("u8g2_font_crox1tb_tr");
extern const uint8_t u8g2_font_crox1tb_tn[] U8G2_FONT_SECTION("u8g2_font_crox1tb_tn");
extern const uint8_t u8g2_font_crox1t_tf[] U8G2_FONT_SECTION("u8g2_font_crox1t_tf");
extern const uint8_t u8g2_font_crox1t_tr[] U8G2_FONT_SECTION("u8g2_font_crox1t_tr");
extern const uint8_t u8g2_font_crox1t_tn[] U8G2_FONT_SECTION("u8g2_font_crox1t_tn");
extern const uint8_t u8g2_font_crox2cb_tf[] U8G2_FONT_SECTION("u8g2_font_crox2cb_tf");
extern const uint8_t u8g2_font_crox2cb_tr[] U8G2_FONT_SECTION("u8g2_font_crox2cb_tr");
extern const uint8_t u8g2_font_crox2cb_tn[] U8G2_FONT_SECTION("u8g2_font_crox2cb_tn");
extern const uint8_t u8g2_font_crox2cb_mf[] U8G2_FONT_SECTION("u8g2_font_crox2cb_mf");
extern const uint8_t u8g2_font_crox2cb_mr[] U8G2_FONT_SECTION("u8g2_font_crox2cb_mr");
extern const uint8_t u8g2_font_crox2cb_mn[] U8G2_FONT_SECTION("u8g2_font_crox2cb_mn");
extern const uint8_t u8g2_font_crox2c_tf[] U8G2_FONT_SECTION("u8g2_font_crox2c_tf");
extern const uint8_t u8g2_font_crox2c_tr[] U8G2_FONT_SECTION("u8g2_font_crox2c_tr");
extern const uint8_t u8g2_font_crox2c_tn[] U8G2_FONT_SECTION("u8g2_font_crox2c_tn");
extern const uint8_t u8g2_font_crox2c_mf[] U8G2_FONT_SECTION("u8g2_font_crox2c_mf");
extern const uint8_t u8g2_font_crox2c_mr[] U8G2_FONT_SECTION("u8g2_font_crox2c_mr");
extern const uint8_t u8g2_font_crox2c_mn[] U8G2_FONT_SECTION("u8g2_font_crox2c_mn");
extern const uint8_t u8g2_font_crox2hb_tf[] U8G2_FONT_SECTION("u8g2_font_crox2hb_tf");
extern const uint8_t u8g2_font_crox2hb_tr[] U8G2_FONT_SECTION("u8g2_font_crox2hb_tr");
extern const uint8_t u8g2_font_crox2hb_tn[] U8G2_FONT_SECTION("u8g2_font_crox2hb_tn");
extern const uint8_t u8g2_font_crox2h_tf[] U8G2_FONT_SECTION("u8g2_font_crox2h_tf");
extern const uint8_t u8g2_font_crox2h_tr[] U8G2_FONT_SECTION("u8g2_font_crox2h_tr");
extern const uint8_t u8g2_font_crox2h_tn[] U8G2_FONT_SECTION("u8g2_font_crox2h_tn");
extern const uint8_t u8g2_font_crox2tb_tf[] U8G2_FONT_SECTION("u8g2_font_crox2tb_tf");
extern const uint8_t u8g2_font_crox2tb_tr[] U8G2_FONT_SECTION("u8g2_font_crox2tb_tr");
extern const uint8_t u8g2_font_crox2tb_tn[] U8G2_FONT_SECTION("u8g2_font_crox2tb_tn");
extern const uint8_t u8g2_font_crox2t_tf[] U8G2_FONT_SECTION("u8g2_font_crox2t_tf");
extern const uint8_t u8g2_font_crox2t_tr[] U8G2_FONT_SECTION("u8g2_font_crox2t_tr");
extern const uint8_t u8g2_font_crox2t_tn[] U8G2_FONT_SECTION("u8g2_font_crox2t_tn");
extern const uint8_t u8g2_font_crox3cb_tf[] U8G2_FONT_SECTION("u8g2_font_crox3cb_tf");
extern const uint8_t u8g2_font_crox3cb_tr[] U8G2_FONT_SECTION("u8g2_font_crox3cb_tr");
extern const uint8_t u8g2_font_crox3cb_tn[] U8G2_FONT_SECTION("u8g2_font_crox3cb_tn");
extern const uint8_t u8g2_font_crox3cb_mf[] U8G2_FONT_SECTION("u8g2_font_crox3cb_mf");
extern const uint8_t u8g2_font_crox3cb_mr[] U8G2_FONT_SECTION("u8g2_font_crox3cb_mr");
extern const uint8_t u8g2_font_crox3cb_mn[] U8G2_FONT_SECTION("u8g2_font_crox3cb_mn");
extern const uint8_t u8g2_font_crox3c_tf[] U8G2_FONT_SECTION("u8g2_font_crox3c_tf");
extern const uint8_t u8g2_font_crox3c_tr[] U8G2_FONT_SECTION("u8g2_font_crox3c_tr");
extern const uint8_t u8g2_font_crox3c_tn[] U8G2_FONT_SECTION("u8g2_font_crox3c_tn");
extern const uint8_t u8g2_font_crox3c_mf[] U8G2_FONT_SECTION("u8g2_font_crox3c_mf");
extern const uint8_t u8g2_font_crox3c_mr[] U8G2_FONT_SECTION("u8g2_font_crox3c_mr");
extern const uint8_t u8g2_font_crox3c_mn[] U8G2_FONT_SECTION("u8g2_font_crox3c_mn");
extern const uint8_t u8g2_font_crox3hb_tf[] U8G2_FONT_SECTION("u8g2_font_crox3hb_tf");
extern const uint8_t u8g2_font_crox3hb_tr[] U8G2_FONT_SECTION("u8g2_font_crox3hb_tr");
extern const uint8_t u8g2_font_crox3hb_tn[] U8G2_FONT_SECTION("u8g2_font_crox3hb_tn");
extern const uint8_t u8g2_font_crox3h_tf[] U8G2_FONT_SECTION("u8g2_font_crox3h_tf");
extern const uint8_t u8g2_font_crox3h_tr[] U8G2_FONT_SECTION("u8g2_font_crox3h_tr");
extern const uint8_t u8g2_font_crox3h_tn[] U8G2_FONT_SECTION("u8g2_font_crox3h_tn");
extern const uint8_t u8g2_font_crox3tb_tf[] U8G2_FONT_SECTION("u8g2_font_crox3tb_tf");
extern const uint8_t u8g2_font_crox3tb_tr[] U8G2_FONT_SECTION("u8g2_font_crox3tb_tr");
extern const uint8_t u8g2_font_crox3tb_tn[] U8G2_FONT_SECTION("u8g2_font_crox3tb_tn");
extern const uint8_t u8g2_font_crox3t_tf[] U8G2_FONT_SECTION("u8g2_font_crox3t_tf");
extern const uint8_t u8g2_font_crox3t_tr[] U8G2_FONT_SECTION("u8g2_font_crox3t_tr");
extern const uint8_t u8g2_font_crox3t_tn[] U8G2_FONT_SECTION("u8g2_font_crox3t_tn");
extern const uint8_t u8g2_font_crox4hb_tf[] U8G2_FONT_SECTION("u8g2_font_crox4hb_tf");
extern const uint8_t u8g2_font_crox4hb_tr[] U8G2_FONT_SECTION("u8g2_font_crox4hb_tr");
extern const uint8_t u8g2_font_crox4hb_tn[] U8G2_FONT_SECTION("u8g2_font_crox4hb_tn");
extern const uint8_t u8g2_font_crox4h_tf[] U8G2_FONT_SECTION("u8g2_font_crox4h_tf");
extern const uint8_t u8g2_font_crox4h_tr[] U8G2_FONT_SECTION("u8g2_font_crox4h_tr");
extern const uint8_t u8g2_font_crox4h_tn[] U8G2_FONT_SECTION("u8g2_font_crox4h_tn");
extern const uint8_t u8g2_font_crox4tb_tf[] U8G2_FONT_SECTION("u8g2_font_crox4tb_tf");
extern const uint8_t u8g2_font_crox4tb_tr[] U8G2_FONT_SECTION("u8g2_font_crox4tb_tr");
extern const uint8_t u8g2_font_crox4tb_tn[] U8G2_FONT_SECTION("u8g2_font_crox4tb_tn");
extern const uint8_t u8g2_font_crox4t_tf[] U8G2_FONT_SECTION("u8g2_font_crox4t_tf");
extern const uint8_t u8g2_font_crox4t_tr[] U8G2_FONT_SECTION("u8g2_font_crox4t_tr");
extern const uint8_t u8g2_font_crox4t_tn[] U8G2_FONT_SECTION("u8g2_font_crox4t_tn");
extern const uint8_t u8g2_font_crox5hb_tf[] U8G2_FONT_SECTION("u8g2_font_crox5hb_tf");
extern const uint8_t u8g2_font_crox5hb_tr[] U8G2_FONT_SECTION("u8g2_font_crox5hb_tr");
extern const uint8_t u8g2_font_crox5hb_tn[] U8G2_FONT_SECTION("u8g2_font_crox5hb_tn");
extern const uint8_t u8g2_font_crox5h_tf[] U8G2_FONT_SECTION("u8g2_font_crox5h_tf");
extern const uint8_t u8g2_font_crox5h_tr[] U8G2_FONT_SECTION("u8g2_font_crox5h_tr");
extern const uint8_t u8g2_font_crox5h_tn[] U8G2_FONT_SECTION("u8g2_font_crox5h_tn");
extern const uint8_t u8g2_font_crox5tb_tf[] U8G2_FONT_SECTION("u8g2_font_crox5tb_tf");
extern const uint8_t u8g2_font_crox5tb_tr[] U8G2_FONT_SECTION("u8g2_font_crox5tb_tr");
extern const uint8_t u8g2_font_crox5tb_tn[] U8G2_FONT_SECTION("u8g2_font_crox5tb_tn");
extern const uint8_t u8g2_font_crox5t_tf[] U8G2_FONT_SECTION("u8g2_font_crox5t_tf");
extern const uint8_t u8g2_font_crox5t_tr[] U8G2_FONT_SECTION("u8g2_font_crox5t_tr");
extern const uint8_t u8g2_font_crox5t_tn[] U8G2_FONT_SECTION("u8g2_font_crox5t_tn");
extern const uint8_t u8g2_font_cu12_tf[] U8G2_FONT_SECTION("u8g2_font_cu12_tf");
extern const uint8_t u8g2_font_cu12_tr[] U8G2_FONT_SECTION("u8g2_font_cu12_tr");
extern const uint8_t u8g2_font_cu12_tn[] U8G2_FONT_SECTION("u8g2_font_cu12_tn");
extern const uint8_t u8g2_font_cu12_te[] U8G2_FONT_SECTION("u8g2_font_cu12_te");
extern const uint8_t u8g2_font_cu12_hf[] U8G2_FONT_SECTION("u8g2_font_cu12_hf");
extern const uint8_t u8g2_font_cu12_hr[] U8G2_FONT_SECTION("u8g2_font_cu12_hr");
extern const uint8_t u8g2_font_cu12_hn[] U8G2_FONT_SECTION("u8g2_font_cu12_hn");
extern const uint8_t u8g2_font_cu12_he[] U8G2_FONT_SECTION("u8g2_font_cu12_he");
extern const uint8_t u8g2_font_cu12_mf[] U8G2_FONT_SECTION("u8g2_font_cu12_mf");
extern const uint8_t u8g2_font_cu12_mr[] U8G2_FONT_SECTION("u8g2_font_cu12_mr");
extern const uint8_t u8g2_font_cu12_mn[] U8G2_FONT_SECTION("u8g2_font_cu12_mn");
extern const uint8_t u8g2_font_cu12_me[] U8G2_FONT_SECTION("u8g2_font_cu12_me");
extern const uint8_t u8g2_font_cu12_t_symbols[] U8G2_FONT_SECTION("u8g2_font_cu12_t_symbols");
extern const uint8_t u8g2_font_cu12_h_symbols[] U8G2_FONT_SECTION("u8g2_font_cu12_h_symbols");
extern const uint8_t u8g2_font_cu12_t_greek[] U8G2_FONT_SECTION("u8g2_font_cu12_t_greek");
extern const uint8_t u8g2_font_cu12_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_cu12_t_cyrillic");
extern const uint8_t u8g2_font_cu12_t_tibetan[] U8G2_FONT_SECTION("u8g2_font_cu12_t_tibetan");
extern const uint8_t u8g2_font_cu12_t_hebrew[] U8G2_FONT_SECTION("u8g2_font_cu12_t_hebrew");
extern const uint8_t u8g2_font_cu12_t_arabic[] U8G2_FONT_SECTION("u8g2_font_cu12_t_arabic");
extern const uint8_t u8g2_font_unifont_tf[] U8G2_FONT_SECTION("u8g2_font_unifont_tf");
extern const uint8_t u8g2_font_unifont_tr[] U8G2_FONT_SECTION("u8g2_font_unifont_tr");
extern const uint8_t u8g2_font_unifont_te[] U8G2_FONT_SECTION("u8g2_font_unifont_te");
extern const uint8_t u8g2_font_unifont_t_latin[] U8G2_FONT_SECTION("u8g2_font_unifont_t_latin");
extern const uint8_t u8g2_font_unifont_t_extended[] U8G2_FONT_SECTION("u8g2_font_unifont_t_extended");
extern const uint8_t u8g2_font_unifont_t_72_73[] U8G2_FONT_SECTION("u8g2_font_unifont_t_72_73");
extern const uint8_t u8g2_font_unifont_t_0_72_73[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_72_73");
extern const uint8_t u8g2_font_unifont_t_75[] U8G2_FONT_SECTION("u8g2_font_unifont_t_75");
extern const uint8_t u8g2_font_unifont_t_0_75[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_75");
extern const uint8_t u8g2_font_unifont_t_76[] U8G2_FONT_SECTION("u8g2_font_unifont_t_76");
extern const uint8_t u8g2_font_unifont_t_0_76[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_76");
extern const uint8_t u8g2_font_unifont_t_77[] U8G2_FONT_SECTION("u8g2_font_unifont_t_77");
extern const uint8_t u8g2_font_unifont_t_0_77[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_77");
extern const uint8_t u8g2_font_unifont_t_78_79[] U8G2_FONT_SECTION("u8g2_font_unifont_t_78_79");
extern const uint8_t u8g2_font_unifont_t_0_78_79[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_78_79");
extern const uint8_t u8g2_font_unifont_t_86[] U8G2_FONT_SECTION("u8g2_font_unifont_t_86");
extern const uint8_t u8g2_font_unifont_t_0_86[] U8G2_FONT_SECTION("u8g2_font_unifont_t_0_86");
extern const uint8_t u8g2_font_unifont_t_greek[] U8G2_FONT_SECTION("u8g2_font_unifont_t_greek");
extern const uint8_t u8g2_font_unifont_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_unifont_t_cyrillic");
extern const uint8_t u8g2_font_unifont_t_hebrew[] U8G2_FONT_SECTION("u8g2_font_unifont_t_hebrew");
extern const uint8_t u8g2_font_unifont_t_bengali[] U8G2_FONT_SECTION("u8g2_font_unifont_t_bengali");
extern const uint8_t u8g2_font_unifont_t_tibetan[] U8G2_FONT_SECTION("u8g2_font_unifont_t_tibetan");
extern const uint8_t u8g2_font_unifont_t_urdu[] U8G2_FONT_SECTION("u8g2_font_unifont_t_urdu");
extern const uint8_t u8g2_font_unifont_t_polish[] U8G2_FONT_SECTION("u8g2_font_unifont_t_polish");
extern const uint8_t u8g2_font_unifont_t_devanagari[] U8G2_FONT_SECTION("u8g2_font_unifont_t_devanagari");
extern const uint8_t u8g2_font_unifont_t_arabic[] U8G2_FONT_SECTION("u8g2_font_unifont_t_arabic");
extern const uint8_t u8g2_font_unifont_t_symbols[] U8G2_FONT_SECTION("u8g2_font_unifont_t_symbols");
extern const uint8_t u8g2_font_unifont_h_symbols[] U8G2_FONT_SECTION("u8g2_font_unifont_h_symbols");
extern const uint8_t u8g2_font_unifont_t_emoticons[] U8G2_FONT_SECTION("u8g2_font_unifont_t_emoticons");
extern const uint8_t u8g2_font_unifont_t_animals[] U8G2_FONT_SECTION("u8g2_font_unifont_t_animals");
extern const uint8_t u8g2_font_unifont_t_domino[] U8G2_FONT_SECTION("u8g2_font_unifont_t_domino");
extern const uint8_t u8g2_font_unifont_t_cards[] U8G2_FONT_SECTION("u8g2_font_unifont_t_cards");
extern const uint8_t u8g2_font_unifont_t_weather[] U8G2_FONT_SECTION("u8g2_font_unifont_t_weather");
extern const uint8_t u8g2_font_unifont_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_unifont_t_chinese1");
extern const uint8_t u8g2_font_unifont_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_unifont_t_chinese2");
extern const uint8_t u8g2_font_unifont_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_unifont_t_chinese3");
extern const uint8_t u8g2_font_unifont_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_unifont_t_gb2312");
extern const uint8_t u8g2_font_unifont_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_unifont_t_gb2312a");
extern const uint8_t u8g2_font_unifont_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_unifont_t_gb2312b");
extern const uint8_t u8g2_font_unifont_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_unifont_t_japanese1");
extern const uint8_t u8g2_font_unifont_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_unifont_t_japanese2");
extern const uint8_t u8g2_font_unifont_t_japanese3[] U8G2_FONT_SECTION("u8g2_font_unifont_t_japanese3");
extern const uint8_t u8g2_font_unifont_t_korean1[] U8G2_FONT_SECTION("u8g2_font_unifont_t_korean1");
extern const uint8_t u8g2_font_unifont_t_korean2[] U8G2_FONT_SECTION("u8g2_font_unifont_t_korean2");
extern const uint8_t u8g2_font_unifont_t_vietnamese1[] U8G2_FONT_SECTION("u8g2_font_unifont_t_vietnamese1");
extern const uint8_t u8g2_font_unifont_t_vietnamese2[] U8G2_FONT_SECTION("u8g2_font_unifont_t_vietnamese2");
extern const uint8_t u8g2_font_gb16st_t_1[] U8G2_FONT_SECTION("u8g2_font_gb16st_t_1");
extern const uint8_t u8g2_font_gb16st_t_2[] U8G2_FONT_SECTION("u8g2_font_gb16st_t_2");
extern const uint8_t u8g2_font_gb16st_t_3[] U8G2_FONT_SECTION("u8g2_font_gb16st_t_3");
extern const uint8_t u8g2_font_gb24st_t_1[] U8G2_FONT_SECTION("u8g2_font_gb24st_t_1");
extern const uint8_t u8g2_font_gb24st_t_2[] U8G2_FONT_SECTION("u8g2_font_gb24st_t_2");
extern const uint8_t u8g2_font_gb24st_t_3[] U8G2_FONT_SECTION("u8g2_font_gb24st_t_3");
extern const uint8_t u8g2_font_wqy12_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_chinese1");
extern const uint8_t u8g2_font_wqy12_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_chinese2");
extern const uint8_t u8g2_font_wqy12_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_chinese3");
extern const uint8_t u8g2_font_wqy12_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_gb2312");
extern const uint8_t u8g2_font_wqy12_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_gb2312a");
extern const uint8_t u8g2_font_wqy12_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_wqy12_t_gb2312b");
extern const uint8_t u8g2_font_wqy13_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_chinese1");
extern const uint8_t u8g2_font_wqy13_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_chinese2");
extern const uint8_t u8g2_font_wqy13_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_chinese3");
extern const uint8_t u8g2_font_wqy13_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_gb2312");
extern const uint8_t u8g2_font_wqy13_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_gb2312a");
extern const uint8_t u8g2_font_wqy13_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_wqy13_t_gb2312b");
extern const uint8_t u8g2_font_wqy14_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_chinese1");
extern const uint8_t u8g2_font_wqy14_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_chinese2");
extern const uint8_t u8g2_font_wqy14_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_chinese3");
extern const uint8_t u8g2_font_wqy14_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_gb2312");
extern const uint8_t u8g2_font_wqy14_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_gb2312a");
extern const uint8_t u8g2_font_wqy14_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_wqy14_t_gb2312b");
extern const uint8_t u8g2_font_wqy15_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_chinese1");
extern const uint8_t u8g2_font_wqy15_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_chinese2");
extern const uint8_t u8g2_font_wqy15_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_chinese3");
extern const uint8_t u8g2_font_wqy15_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_gb2312");
extern const uint8_t u8g2_font_wqy15_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_gb2312a");
extern const uint8_t u8g2_font_wqy15_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_wqy15_t_gb2312b");
extern const uint8_t u8g2_font_wqy16_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_chinese1");
extern const uint8_t u8g2_font_wqy16_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_chinese2");
extern const uint8_t u8g2_font_wqy16_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_chinese3");
extern const uint8_t u8g2_font_wqy16_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_gb2312");
extern const uint8_t u8g2_font_wqy16_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_gb2312a");
extern const uint8_t u8g2_font_wqy16_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_wqy16_t_gb2312b");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_tf[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_tf");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_tr[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_tr");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_tn[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_tn");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_te[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_te");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_all[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_all");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_chinese1");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_chinese2");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_chinese3");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_gb2312");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_gb2312a");
extern const uint8_t u8g2_font_boutique_bitmap_7x7_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_7x7_t_gb2312b");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_tf[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_tf");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_tr[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_tr");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_tn[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_tn");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_te[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_te");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_all[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_all");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_chinese1");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_chinese2");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_chinese3");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_gb2312");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_gb2312a");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_t_gb2312b");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_tf[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_tf");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_tr[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_tr");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_tn[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_tn");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_te[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_te");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_all[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_all");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_chinese1[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_chinese1");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_chinese2[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_chinese2");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_chinese3[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_chinese3");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_gb2312[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_gb2312");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_gb2312a[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_gb2312a");
extern const uint8_t u8g2_font_boutique_bitmap_9x9_bold_t_gb2312b[] U8G2_FONT_SECTION("u8g2_font_boutique_bitmap_9x9_bold_t_gb2312b");
extern const uint8_t u8g2_font_b10_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b10_t_japanese1");
extern const uint8_t u8g2_font_b10_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b10_t_japanese2");
extern const uint8_t u8g2_font_b10_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b10_b_t_japanese1");
extern const uint8_t u8g2_font_b10_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b10_b_t_japanese2");
extern const uint8_t u8g2_font_f10_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f10_t_japanese1");
extern const uint8_t u8g2_font_f10_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f10_t_japanese2");
extern const uint8_t u8g2_font_f10_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f10_b_t_japanese1");
extern const uint8_t u8g2_font_f10_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f10_b_t_japanese2");
extern const uint8_t u8g2_font_b12_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b12_t_japanese1");
extern const uint8_t u8g2_font_b12_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b12_t_japanese2");
extern const uint8_t u8g2_font_b12_t_japanese3[] U8G2_FONT_SECTION("u8g2_font_b12_t_japanese3");
extern const uint8_t u8g2_font_b12_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b12_b_t_japanese1");
extern const uint8_t u8g2_font_b12_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b12_b_t_japanese2");
extern const uint8_t u8g2_font_b12_b_t_japanese3[] U8G2_FONT_SECTION("u8g2_font_b12_b_t_japanese3");
extern const uint8_t u8g2_font_f12_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f12_t_japanese1");
extern const uint8_t u8g2_font_f12_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f12_t_japanese2");
extern const uint8_t u8g2_font_f12_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f12_b_t_japanese1");
extern const uint8_t u8g2_font_f12_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f12_b_t_japanese2");
extern const uint8_t u8g2_font_b16_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b16_t_japanese1");
extern const uint8_t u8g2_font_b16_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b16_t_japanese2");
extern const uint8_t u8g2_font_b16_t_japanese3[] U8G2_FONT_SECTION("u8g2_font_b16_t_japanese3");
extern const uint8_t u8g2_font_b16_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_b16_b_t_japanese1");
extern const uint8_t u8g2_font_b16_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_b16_b_t_japanese2");
extern const uint8_t u8g2_font_b16_b_t_japanese3[] U8G2_FONT_SECTION("u8g2_font_b16_b_t_japanese3");
extern const uint8_t u8g2_font_f16_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f16_t_japanese1");
extern const uint8_t u8g2_font_f16_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f16_t_japanese2");
extern const uint8_t u8g2_font_f16_b_t_japanese1[] U8G2_FONT_SECTION("u8g2_font_f16_b_t_japanese1");
extern const uint8_t u8g2_font_f16_b_t_japanese2[] U8G2_FONT_SECTION("u8g2_font_f16_b_t_japanese2");
extern const uint8_t u8g2_font_artossans8_8r[] U8G2_FONT_SECTION("u8g2_font_artossans8_8r");
extern const uint8_t u8g2_font_artossans8_8n[] U8G2_FONT_SECTION("u8g2_font_artossans8_8n");
extern const uint8_t u8g2_font_artossans8_8u[] U8G2_FONT_SECTION("u8g2_font_artossans8_8u");
extern const uint8_t u8g2_font_artosserif8_8r[] U8G2_FONT_SECTION("u8g2_font_artosserif8_8r");
extern const uint8_t u8g2_font_artosserif8_8n[] U8G2_FONT_SECTION("u8g2_font_artosserif8_8n");
extern const uint8_t u8g2_font_artosserif8_8u[] U8G2_FONT_SECTION("u8g2_font_artosserif8_8u");
extern const uint8_t u8g2_font_chroma48medium8_8r[] U8G2_FONT_SECTION("u8g2_font_chroma48medium8_8r");
extern const uint8_t u8g2_font_chroma48medium8_8n[] U8G2_FONT_SECTION("u8g2_font_chroma48medium8_8n");
extern const uint8_t u8g2_font_chroma48medium8_8u[] U8G2_FONT_SECTION("u8g2_font_chroma48medium8_8u");
extern const uint8_t u8g2_font_saikyosansbold8_8n[] U8G2_FONT_SECTION("u8g2_font_saikyosansbold8_8n");
extern const uint8_t u8g2_font_saikyosansbold8_8u[] U8G2_FONT_SECTION("u8g2_font_saikyosansbold8_8u");
extern const uint8_t u8g2_font_torussansbold8_8r[] U8G2_FONT_SECTION("u8g2_font_torussansbold8_8r");
extern const uint8_t u8g2_font_torussansbold8_8n[] U8G2_FONT_SECTION("u8g2_font_torussansbold8_8n");
extern const uint8_t u8g2_font_torussansbold8_8u[] U8G2_FONT_SECTION("u8g2_font_torussansbold8_8u");
extern const uint8_t u8g2_font_victoriabold8_8r[] U8G2_FONT_SECTION("u8g2_font_victoriabold8_8r");
extern const uint8_t u8g2_font_victoriabold8_8n[] U8G2_FONT_SECTION("u8g2_font_victoriabold8_8n");
extern const uint8_t u8g2_font_victoriabold8_8u[] U8G2_FONT_SECTION("u8g2_font_victoriabold8_8u");
extern const uint8_t u8g2_font_victoriamedium8_8r[] U8G2_FONT_SECTION("u8g2_font_victoriamedium8_8r");
extern const uint8_t u8g2_font_victoriamedium8_8n[] U8G2_FONT_SECTION("u8g2_font_victoriamedium8_8n");
extern const uint8_t u8g2_font_victoriamedium8_8u[] U8G2_FONT_SECTION("u8g2_font_victoriamedium8_8u");
extern const uint8_t u8g2_font_courB08_tf[] U8G2_FONT_SECTION("u8g2_font_courB08_tf");
extern const uint8_t u8g2_font_courB08_tr[] U8G2_FONT_SECTION("u8g2_font_courB08_tr");
extern const uint8_t u8g2_font_courB08_tn[] U8G2_FONT_SECTION("u8g2_font_courB08_tn");
extern const uint8_t u8g2_font_courB10_tf[] U8G2_FONT_SECTION("u8g2_font_courB10_tf");
extern const uint8_t u8g2_font_courB10_tr[] U8G2_FONT_SECTION("u8g2_font_courB10_tr");
extern const uint8_t u8g2_font_courB10_tn[] U8G2_FONT_SECTION("u8g2_font_courB10_tn");
extern const uint8_t u8g2_font_courB12_tf[] U8G2_FONT_SECTION("u8g2_font_courB12_tf");
extern const uint8_t u8g2_font_courB12_tr[] U8G2_FONT_SECTION("u8g2_font_courB12_tr");
extern const uint8_t u8g2_font_courB12_tn[] U8G2_FONT_SECTION("u8g2_font_courB12_tn");
extern const uint8_t u8g2_font_courB14_tf[] U8G2_FONT_SECTION("u8g2_font_courB14_tf");
extern const uint8_t u8g2_font_courB14_tr[] U8G2_FONT_SECTION("u8g2_font_courB14_tr");
extern const uint8_t u8g2_font_courB14_tn[] U8G2_FONT_SECTION("u8g2_font_courB14_tn");
extern const uint8_t u8g2_font_courB18_tf[] U8G2_FONT_SECTION("u8g2_font_courB18_tf");
extern const uint8_t u8g2_font_courB18_tr[] U8G2_FONT_SECTION("u8g2_font_courB18_tr");
extern const uint8_t u8g2_font_courB18_tn[] U8G2_FONT_SECTION("u8g2_font_courB18_tn");
extern const uint8_t u8g2_font_courB24_tf[] U8G2_FONT_SECTION("u8g2_font_courB24_tf");
extern const uint8_t u8g2_font_courB24_tr[] U8G2_FONT_SECTION("u8g2_font_courB24_tr");
extern const uint8_t u8g2_font_courB24_tn[] U8G2_FONT_SECTION("u8g2_font_courB24_tn");
extern const uint8_t u8g2_font_courR08_tf[] U8G2_FONT_SECTION("u8g2_font_courR08_tf");
extern const uint8_t u8g2_font_courR08_tr[] U8G2_FONT_SECTION("u8g2_font_courR08_tr");
extern const uint8_t u8g2_font_courR08_tn[] U8G2_FONT_SECTION("u8g2_font_courR08_tn");
extern const uint8_t u8g2_font_courR10_tf[] U8G2_FONT_SECTION("u8g2_font_courR10_tf");
extern const uint8_t u8g2_font_courR10_tr[] U8G2_FONT_SECTION("u8g2_font_courR10_tr");
extern const uint8_t u8g2_font_courR10_tn[] U8G2_FONT_SECTION("u8g2_font_courR10_tn");
extern const uint8_t u8g2_font_courR12_tf[] U8G2_FONT_SECTION("u8g2_font_courR12_tf");
extern const uint8_t u8g2_font_courR12_tr[] U8G2_FONT_SECTION("u8g2_font_courR12_tr");
extern const uint8_t u8g2_font_courR12_tn[] U8G2_FONT_SECTION("u8g2_font_courR12_tn");
extern const uint8_t u8g2_font_courR14_tf[] U8G2_FONT_SECTION("u8g2_font_courR14_tf");
extern const uint8_t u8g2_font_courR14_tr[] U8G2_FONT_SECTION("u8g2_font_courR14_tr");
extern const uint8_t u8g2_font_courR14_tn[] U8G2_FONT_SECTION("u8g2_font_courR14_tn");
extern const uint8_t u8g2_font_courR18_tf[] U8G2_FONT_SECTION("u8g2_font_courR18_tf");
extern const uint8_t u8g2_font_courR18_tr[] U8G2_FONT_SECTION("u8g2_font_courR18_tr");
extern const uint8_t u8g2_font_courR18_tn[] U8G2_FONT_SECTION("u8g2_font_courR18_tn");
extern const uint8_t u8g2_font_courR24_tf[] U8G2_FONT_SECTION("u8g2_font_courR24_tf");
extern const uint8_t u8g2_font_courR24_tr[] U8G2_FONT_SECTION("u8g2_font_courR24_tr");
extern const uint8_t u8g2_font_courR24_tn[] U8G2_FONT_SECTION("u8g2_font_courR24_tn");
extern const uint8_t u8g2_font_helvB08_tf[] U8G2_FONT_SECTION("u8g2_font_helvB08_tf");
extern const uint8_t u8g2_font_helvB08_tr[] U8G2_FONT_SECTION("u8g2_font_helvB08_tr");
extern const uint8_t u8g2_font_helvB08_tn[] U8G2_FONT_SECTION("u8g2_font_helvB08_tn");
extern const uint8_t u8g2_font_helvB08_te[] U8G2_FONT_SECTION("u8g2_font_helvB08_te");
extern const uint8_t u8g2_font_helvB10_tf[] U8G2_FONT_SECTION("u8g2_font_helvB10_tf");
extern const uint8_t u8g2_font_helvB10_tr[] U8G2_FONT_SECTION("u8g2_font_helvB10_tr");
extern const uint8_t u8g2_font_helvB10_tn[] U8G2_FONT_SECTION("u8g2_font_helvB10_tn");
extern const uint8_t u8g2_font_helvB10_te[] U8G2_FONT_SECTION("u8g2_font_helvB10_te");
extern const uint8_t u8g2_font_helvB12_tf[] U8G2_FONT_SECTION("u8g2_font_helvB12_tf");
extern const uint8_t u8g2_font_helvB12_tr[] U8G2_FONT_SECTION("u8g2_font_helvB12_tr");
extern const uint8_t u8g2_font_helvB12_tn[] U8G2_FONT_SECTION("u8g2_font_helvB12_tn");
extern const uint8_t u8g2_font_helvB12_te[] U8G2_FONT_SECTION("u8g2_font_helvB12_te");
extern const uint8_t u8g2_font_helvB14_tf[] U8G2_FONT_SECTION("u8g2_font_helvB14_tf");
extern const uint8_t u8g2_font_helvB14_tr[] U8G2_FONT_SECTION("u8g2_font_helvB14_tr");
extern const uint8_t u8g2_font_helvB14_tn[] U8G2_FONT_SECTION("u8g2_font_helvB14_tn");
extern const uint8_t u8g2_font_helvB14_te[] U8G2_FONT_SECTION("u8g2_font_helvB14_te");
extern const uint8_t u8g2_font_helvB18_tf[] U8G2_FONT_SECTION("u8g2_font_helvB18_tf");
extern const uint8_t u8g2_font_helvB18_tr[] U8G2_FONT_SECTION("u8g2_font_helvB18_tr");
extern const uint8_t u8g2_font_helvB18_tn[] U8G2_FONT_SECTION("u8g2_font_helvB18_tn");
extern const uint8_t u8g2_font_helvB18_te[] U8G2_FONT_SECTION("u8g2_font_helvB18_te");
extern const uint8_t u8g2_font_helvB24_tf[] U8G2_FONT_SECTION("u8g2_font_helvB24_tf");
extern const uint8_t u8g2_font_helvB24_tr[] U8G2_FONT_SECTION("u8g2_font_helvB24_tr");
extern const uint8_t u8g2_font_helvB24_tn[] U8G2_FONT_SECTION("u8g2_font_helvB24_tn");
extern const uint8_t u8g2_font_helvB24_te[] U8G2_FONT_SECTION("u8g2_font_helvB24_te");
extern const uint8_t u8g2_font_helvR08_tf[] U8G2_FONT_SECTION("u8g2_font_helvR08_tf");
extern const uint8_t u8g2_font_helvR08_tr[] U8G2_FONT_SECTION("u8g2_font_helvR08_tr");
extern const uint8_t u8g2_font_helvR08_tn[] U8G2_FONT_SECTION("u8g2_font_helvR08_tn");
extern const uint8_t u8g2_font_helvR08_te[] U8G2_FONT_SECTION("u8g2_font_helvR08_te");
extern const uint8_t u8g2_font_helvR10_tf[] U8G2_FONT_SECTION("u8g2_font_helvR10_tf");
extern const uint8_t u8g2_font_helvR10_tr[] U8G2_FONT_SECTION("u8g2_font_helvR10_tr");
extern const uint8_t u8g2_font_helvR10_tn[] U8G2_FONT_SECTION("u8g2_font_helvR10_tn");
extern const uint8_t u8g2_font_helvR10_te[] U8G2_FONT_SECTION("u8g2_font_helvR10_te");
extern const uint8_t u8g2_font_helvR12_tf[] U8G2_FONT_SECTION("u8g2_font_helvR12_tf");
extern const uint8_t u8g2_font_helvR12_tr[] U8G2_FONT_SECTION("u8g2_font_helvR12_tr");
extern const uint8_t u8g2_font_helvR12_tn[] U8G2_FONT_SECTION("u8g2_font_helvR12_tn");
extern const uint8_t u8g2_font_helvR12_te[] U8G2_FONT_SECTION("u8g2_font_helvR12_te");
extern const uint8_t u8g2_font_helvR14_tf[] U8G2_FONT_SECTION("u8g2_font_helvR14_tf");
extern const uint8_t u8g2_font_helvR14_tr[] U8G2_FONT_SECTION("u8g2_font_helvR14_tr");
extern const uint8_t u8g2_font_helvR14_tn[] U8G2_FONT_SECTION("u8g2_font_helvR14_tn");
extern const uint8_t u8g2_font_helvR14_te[] U8G2_FONT_SECTION("u8g2_font_helvR14_te");
extern const uint8_t u8g2_font_helvR18_tf[] U8G2_FONT_SECTION("u8g2_font_helvR18_tf");
extern const uint8_t u8g2_font_helvR18_tr[] U8G2_FONT_SECTION("u8g2_font_helvR18_tr");
extern const uint8_t u8g2_font_helvR18_tn[] U8G2_FONT_SECTION("u8g2_font_helvR18_tn");
extern const uint8_t u8g2_font_helvR18_te[] U8G2_FONT_SECTION("u8g2_font_helvR18_te");
extern const uint8_t u8g2_font_helvR24_tf[] U8G2_FONT_SECTION("u8g2_font_helvR24_tf");
extern const uint8_t u8g2_font_helvR24_tr[] U8G2_FONT_SECTION("u8g2_font_helvR24_tr");
extern const uint8_t u8g2_font_helvR24_tn[] U8G2_FONT_SECTION("u8g2_font_helvR24_tn");
extern const uint8_t u8g2_font_helvR24_te[] U8G2_FONT_SECTION("u8g2_font_helvR24_te");
extern const uint8_t u8g2_font_ncenB08_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB08_tf");
extern const uint8_t u8g2_font_ncenB08_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB08_tr");
extern const uint8_t u8g2_font_ncenB08_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB08_tn");
extern const uint8_t u8g2_font_ncenB08_te[] U8G2_FONT_SECTION("u8g2_font_ncenB08_te");
extern const uint8_t u8g2_font_ncenB10_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB10_tf");
extern const uint8_t u8g2_font_ncenB10_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB10_tr");
extern const uint8_t u8g2_font_ncenB10_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB10_tn");
extern const uint8_t u8g2_font_ncenB10_te[] U8G2_FONT_SECTION("u8g2_font_ncenB10_te");
extern const uint8_t u8g2_font_ncenB12_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB12_tf");
extern const uint8_t u8g2_font_ncenB12_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB12_tr");
extern const uint8_t u8g2_font_ncenB12_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB12_tn");
extern const uint8_t u8g2_font_ncenB12_te[] U8G2_FONT_SECTION("u8g2_font_ncenB12_te");
extern const uint8_t u8g2_font_ncenB14_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB14_tf");
extern const uint8_t u8g2_font_ncenB14_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB14_tr");
extern const uint8_t u8g2_font_ncenB14_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB14_tn");
extern const uint8_t u8g2_font_ncenB14_te[] U8G2_FONT_SECTION("u8g2_font_ncenB14_te");
extern const uint8_t u8g2_font_ncenB18_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB18_tf");
extern const uint8_t u8g2_font_ncenB18_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB18_tr");
extern const uint8_t u8g2_font_ncenB18_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB18_tn");
extern const uint8_t u8g2_font_ncenB18_te[] U8G2_FONT_SECTION("u8g2_font_ncenB18_te");
extern const uint8_t u8g2_font_ncenB24_tf[] U8G2_FONT_SECTION("u8g2_font_ncenB24_tf");
extern const uint8_t u8g2_font_ncenB24_tr[] U8G2_FONT_SECTION("u8g2_font_ncenB24_tr");
extern const uint8_t u8g2_font_ncenB24_tn[] U8G2_FONT_SECTION("u8g2_font_ncenB24_tn");
extern const uint8_t u8g2_font_ncenB24_te[] U8G2_FONT_SECTION("u8g2_font_ncenB24_te");
extern const uint8_t u8g2_font_ncenR08_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR08_tf");
extern const uint8_t u8g2_font_ncenR08_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR08_tr");
extern const uint8_t u8g2_font_ncenR08_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR08_tn");
extern const uint8_t u8g2_font_ncenR08_te[] U8G2_FONT_SECTION("u8g2_font_ncenR08_te");
extern const uint8_t u8g2_font_ncenR10_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR10_tf");
extern const uint8_t u8g2_font_ncenR10_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR10_tr");
extern const uint8_t u8g2_font_ncenR10_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR10_tn");
extern const uint8_t u8g2_font_ncenR10_te[] U8G2_FONT_SECTION("u8g2_font_ncenR10_te");
extern const uint8_t u8g2_font_ncenR12_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR12_tf");
extern const uint8_t u8g2_font_ncenR12_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR12_tr");
extern const uint8_t u8g2_font_ncenR12_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR12_tn");
extern const uint8_t u8g2_font_ncenR12_te[] U8G2_FONT_SECTION("u8g2_font_ncenR12_te");
extern const uint8_t u8g2_font_ncenR14_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR14_tf");
extern const uint8_t u8g2_font_ncenR14_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR14_tr");
extern const uint8_t u8g2_font_ncenR14_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR14_tn");
extern const uint8_t u8g2_font_ncenR14_te[] U8G2_FONT_SECTION("u8g2_font_ncenR14_te");
extern const uint8_t u8g2_font_ncenR18_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR18_tf");
extern const uint8_t u8g2_font_ncenR18_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR18_tr");
extern const uint8_t u8g2_font_ncenR18_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR18_tn");
extern const uint8_t u8g2_font_ncenR18_te[] U8G2_FONT_SECTION("u8g2_font_ncenR18_te");
extern const uint8_t u8g2_font_ncenR24_tf[] U8G2_FONT_SECTION("u8g2_font_ncenR24_tf");
extern const uint8_t u8g2_font_ncenR24_tr[] U8G2_FONT_SECTION("u8g2_font_ncenR24_tr");
extern const uint8_t u8g2_font_ncenR24_tn[] U8G2_FONT_SECTION("u8g2_font_ncenR24_tn");
extern const uint8_t u8g2_font_ncenR24_te[] U8G2_FONT_SECTION("u8g2_font_ncenR24_te");
extern const uint8_t u8g2_font_timB08_tf[] U8G2_FONT_SECTION("u8g2_font_timB08_tf");
extern const uint8_t u8g2_font_timB08_tr[] U8G2_FONT_SECTION("u8g2_font_timB08_tr");
extern const uint8_t u8g2_font_timB08_tn[] U8G2_FONT_SECTION("u8g2_font_timB08_tn");
extern const uint8_t u8g2_font_timB10_tf[] U8G2_FONT_SECTION("u8g2_font_timB10_tf");
extern const uint8_t u8g2_font_timB10_tr[] U8G2_FONT_SECTION("u8g2_font_timB10_tr");
extern const uint8_t u8g2_font_timB10_tn[] U8G2_FONT_SECTION("u8g2_font_timB10_tn");
extern const uint8_t u8g2_font_timB12_tf[] U8G2_FONT_SECTION("u8g2_font_timB12_tf");
extern const uint8_t u8g2_font_timB12_tr[] U8G2_FONT_SECTION("u8g2_font_timB12_tr");
extern const uint8_t u8g2_font_timB12_tn[] U8G2_FONT_SECTION("u8g2_font_timB12_tn");
extern const uint8_t u8g2_font_timB14_tf[] U8G2_FONT_SECTION("u8g2_font_timB14_tf");
extern const uint8_t u8g2_font_timB14_tr[] U8G2_FONT_SECTION("u8g2_font_timB14_tr");
extern const uint8_t u8g2_font_timB14_tn[] U8G2_FONT_SECTION("u8g2_font_timB14_tn");
extern const uint8_t u8g2_font_timB18_tf[] U8G2_FONT_SECTION("u8g2_font_timB18_tf");
extern const uint8_t u8g2_font_timB18_tr[] U8G2_FONT_SECTION("u8g2_font_timB18_tr");
extern const uint8_t u8g2_font_timB18_tn[] U8G2_FONT_SECTION("u8g2_font_timB18_tn");
extern const uint8_t u8g2_font_timB24_tf[] U8G2_FONT_SECTION("u8g2_font_timB24_tf");
extern const uint8_t u8g2_font_timB24_tr[] U8G2_FONT_SECTION("u8g2_font_timB24_tr");
extern const uint8_t u8g2_font_timB24_tn[] U8G2_FONT_SECTION("u8g2_font_timB24_tn");
extern const uint8_t u8g2_font_timR08_tf[] U8G2_FONT_SECTION("u8g2_font_timR08_tf");
extern const uint8_t u8g2_font_timR08_tr[] U8G2_FONT_SECTION("u8g2_font_timR08_tr");
extern const uint8_t u8g2_font_timR08_tn[] U8G2_FONT_SECTION("u8g2_font_timR08_tn");
extern const uint8_t u8g2_font_timR10_tf[] U8G2_FONT_SECTION("u8g2_font_timR10_tf");
extern const uint8_t u8g2_font_timR10_tr[] U8G2_FONT_SECTION("u8g2_font_timR10_tr");
extern const uint8_t u8g2_font_timR10_tn[] U8G2_FONT_SECTION("u8g2_font_timR10_tn");
extern const uint8_t u8g2_font_timR12_tf[] U8G2_FONT_SECTION("u8g2_font_timR12_tf");
extern const uint8_t u8g2_font_timR12_tr[] U8G2_FONT_SECTION("u8g2_font_timR12_tr");
extern const uint8_t u8g2_font_timR12_tn[] U8G2_FONT_SECTION("u8g2_font_timR12_tn");
extern const uint8_t u8g2_font_timR14_tf[] U8G2_FONT_SECTION("u8g2_font_timR14_tf");
extern const uint8_t u8g2_font_timR14_tr[] U8G2_FONT_SECTION("u8g2_font_timR14_tr");
extern const uint8_t u8g2_font_timR14_tn[] U8G2_FONT_SECTION("u8g2_font_timR14_tn");
extern const uint8_t u8g2_font_timR18_tf[] U8G2_FONT_SECTION("u8g2_font_timR18_tf");
extern const uint8_t u8g2_font_timR18_tr[] U8G2_FONT_SECTION("u8g2_font_timR18_tr");
extern const uint8_t u8g2_font_timR18_tn[] U8G2_FONT_SECTION("u8g2_font_timR18_tn");
extern const uint8_t u8g2_font_timR24_tf[] U8G2_FONT_SECTION("u8g2_font_timR24_tf");
extern const uint8_t u8g2_font_timR24_tr[] U8G2_FONT_SECTION("u8g2_font_timR24_tr");
extern const uint8_t u8g2_font_timR24_tn[] U8G2_FONT_SECTION("u8g2_font_timR24_tn");
extern const uint8_t u8g2_font_lubB08_tf[] U8G2_FONT_SECTION("u8g2_font_lubB08_tf");
extern const uint8_t u8g2_font_lubB08_tr[] U8G2_FONT_SECTION("u8g2_font_lubB08_tr");
extern const uint8_t u8g2_font_lubB08_tn[] U8G2_FONT_SECTION("u8g2_font_lubB08_tn");
extern const uint8_t u8g2_font_lubB08_te[] U8G2_FONT_SECTION("u8g2_font_lubB08_te");
extern const uint8_t u8g2_font_lubB10_tf[] U8G2_FONT_SECTION("u8g2_font_lubB10_tf");
extern const uint8_t u8g2_font_lubB10_tr[] U8G2_FONT_SECTION("u8g2_font_lubB10_tr");
extern const uint8_t u8g2_font_lubB10_tn[] U8G2_FONT_SECTION("u8g2_font_lubB10_tn");
extern const uint8_t u8g2_font_lubB10_te[] U8G2_FONT_SECTION("u8g2_font_lubB10_te");
extern const uint8_t u8g2_font_lubB12_tf[] U8G2_FONT_SECTION("u8g2_font_lubB12_tf");
extern const uint8_t u8g2_font_lubB12_tr[] U8G2_FONT_SECTION("u8g2_font_lubB12_tr");
extern const uint8_t u8g2_font_lubB12_tn[] U8G2_FONT_SECTION("u8g2_font_lubB12_tn");
extern const uint8_t u8g2_font_lubB12_te[] U8G2_FONT_SECTION("u8g2_font_lubB12_te");
extern const uint8_t u8g2_font_lubB14_tf[] U8G2_FONT_SECTION("u8g2_font_lubB14_tf");
extern const uint8_t u8g2_font_lubB14_tr[] U8G2_FONT_SECTION("u8g2_font_lubB14_tr");
extern const uint8_t u8g2_font_lubB14_tn[] U8G2_FONT_SECTION("u8g2_font_lubB14_tn");
extern const uint8_t u8g2_font_lubB14_te[] U8G2_FONT_SECTION("u8g2_font_lubB14_te");
extern const uint8_t u8g2_font_lubB18_tf[] U8G2_FONT_SECTION("u8g2_font_lubB18_tf");
extern const uint8_t u8g2_font_lubB18_tr[] U8G2_FONT_SECTION("u8g2_font_lubB18_tr");
extern const uint8_t u8g2_font_lubB18_tn[] U8G2_FONT_SECTION("u8g2_font_lubB18_tn");
extern const uint8_t u8g2_font_lubB18_te[] U8G2_FONT_SECTION("u8g2_font_lubB18_te");
extern const uint8_t u8g2_font_lubB19_tf[] U8G2_FONT_SECTION("u8g2_font_lubB19_tf");
extern const uint8_t u8g2_font_lubB19_tr[] U8G2_FONT_SECTION("u8g2_font_lubB19_tr");
extern const uint8_t u8g2_font_lubB19_tn[] U8G2_FONT_SECTION("u8g2_font_lubB19_tn");
extern const uint8_t u8g2_font_lubB19_te[] U8G2_FONT_SECTION("u8g2_font_lubB19_te");
extern const uint8_t u8g2_font_lubB24_tf[] U8G2_FONT_SECTION("u8g2_font_lubB24_tf");
extern const uint8_t u8g2_font_lubB24_tr[] U8G2_FONT_SECTION("u8g2_font_lubB24_tr");
extern const uint8_t u8g2_font_lubB24_tn[] U8G2_FONT_SECTION("u8g2_font_lubB24_tn");
extern const uint8_t u8g2_font_lubB24_te[] U8G2_FONT_SECTION("u8g2_font_lubB24_te");
extern const uint8_t u8g2_font_lubBI08_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI08_tf");
extern const uint8_t u8g2_font_lubBI08_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI08_tr");
extern const uint8_t u8g2_font_lubBI08_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI08_tn");
extern const uint8_t u8g2_font_lubBI08_te[] U8G2_FONT_SECTION("u8g2_font_lubBI08_te");
extern const uint8_t u8g2_font_lubBI10_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI10_tf");
extern const uint8_t u8g2_font_lubBI10_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI10_tr");
extern const uint8_t u8g2_font_lubBI10_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI10_tn");
extern const uint8_t u8g2_font_lubBI10_te[] U8G2_FONT_SECTION("u8g2_font_lubBI10_te");
extern const uint8_t u8g2_font_lubBI12_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI12_tf");
extern const uint8_t u8g2_font_lubBI12_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI12_tr");
extern const uint8_t u8g2_font_lubBI12_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI12_tn");
extern const uint8_t u8g2_font_lubBI12_te[] U8G2_FONT_SECTION("u8g2_font_lubBI12_te");
extern const uint8_t u8g2_font_lubBI14_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI14_tf");
extern const uint8_t u8g2_font_lubBI14_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI14_tr");
extern const uint8_t u8g2_font_lubBI14_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI14_tn");
extern const uint8_t u8g2_font_lubBI14_te[] U8G2_FONT_SECTION("u8g2_font_lubBI14_te");
extern const uint8_t u8g2_font_lubBI18_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI18_tf");
extern const uint8_t u8g2_font_lubBI18_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI18_tr");
extern const uint8_t u8g2_font_lubBI18_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI18_tn");
extern const uint8_t u8g2_font_lubBI18_te[] U8G2_FONT_SECTION("u8g2_font_lubBI18_te");
extern const uint8_t u8g2_font_lubBI19_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI19_tf");
extern const uint8_t u8g2_font_lubBI19_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI19_tr");
extern const uint8_t u8g2_font_lubBI19_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI19_tn");
extern const uint8_t u8g2_font_lubBI19_te[] U8G2_FONT_SECTION("u8g2_font_lubBI19_te");
extern const uint8_t u8g2_font_lubBI24_tf[] U8G2_FONT_SECTION("u8g2_font_lubBI24_tf");
extern const uint8_t u8g2_font_lubBI24_tr[] U8G2_FONT_SECTION("u8g2_font_lubBI24_tr");
extern const uint8_t u8g2_font_lubBI24_tn[] U8G2_FONT_SECTION("u8g2_font_lubBI24_tn");
extern const uint8_t u8g2_font_lubBI24_te[] U8G2_FONT_SECTION("u8g2_font_lubBI24_te");
extern const uint8_t u8g2_font_lubI08_tf[] U8G2_FONT_SECTION("u8g2_font_lubI08_tf");
extern const uint8_t u8g2_font_lubI08_tr[] U8G2_FONT_SECTION("u8g2_font_lubI08_tr");
extern const uint8_t u8g2_font_lubI08_tn[] U8G2_FONT_SECTION("u8g2_font_lubI08_tn");
extern const uint8_t u8g2_font_lubI08_te[] U8G2_FONT_SECTION("u8g2_font_lubI08_te");
extern const uint8_t u8g2_font_lubI10_tf[] U8G2_FONT_SECTION("u8g2_font_lubI10_tf");
extern const uint8_t u8g2_font_lubI10_tr[] U8G2_FONT_SECTION("u8g2_font_lubI10_tr");
extern const uint8_t u8g2_font_lubI10_tn[] U8G2_FONT_SECTION("u8g2_font_lubI10_tn");
extern const uint8_t u8g2_font_lubI10_te[] U8G2_FONT_SECTION("u8g2_font_lubI10_te");
extern const uint8_t u8g2_font_lubI12_tf[] U8G2_FONT_SECTION("u8g2_font_lubI12_tf");
extern const uint8_t u8g2_font_lubI12_tr[] U8G2_FONT_SECTION("u8g2_font_lubI12_tr");
extern const uint8_t u8g2_font_lubI12_tn[] U8G2_FONT_SECTION("u8g2_font_lubI12_tn");
extern const uint8_t u8g2_font_lubI12_te[] U8G2_FONT_SECTION("u8g2_font_lubI12_te");
extern const uint8_t u8g2_font_lubI14_tf[] U8G2_FONT_SECTION("u8g2_font_lubI14_tf");
extern const uint8_t u8g2_font_lubI14_tr[] U8G2_FONT_SECTION("u8g2_font_lubI14_tr");
extern const uint8_t u8g2_font_lubI14_tn[] U8G2_FONT_SECTION("u8g2_font_lubI14_tn");
extern const uint8_t u8g2_font_lubI14_te[] U8G2_FONT_SECTION("u8g2_font_lubI14_te");
extern const uint8_t u8g2_font_lubI18_tf[] U8G2_FONT_SECTION("u8g2_font_lubI18_tf");
extern const uint8_t u8g2_font_lubI18_tr[] U8G2_FONT_SECTION("u8g2_font_lubI18_tr");
extern const uint8_t u8g2_font_lubI18_tn[] U8G2_FONT_SECTION("u8g2_font_lubI18_tn");
extern const uint8_t u8g2_font_lubI18_te[] U8G2_FONT_SECTION("u8g2_font_lubI18_te");
extern const uint8_t u8g2_font_lubI19_tf[] U8G2_FONT_SECTION("u8g2_font_lubI19_tf");
extern const uint8_t u8g2_font_lubI19_tr[] U8G2_FONT_SECTION("u8g2_font_lubI19_tr");
extern const uint8_t u8g2_font_lubI19_tn[] U8G2_FONT_SECTION("u8g2_font_lubI19_tn");
extern const uint8_t u8g2_font_lubI19_te[] U8G2_FONT_SECTION("u8g2_font_lubI19_te");
extern const uint8_t u8g2_font_lubI24_tf[] U8G2_FONT_SECTION("u8g2_font_lubI24_tf");
extern const uint8_t u8g2_font_lubI24_tr[] U8G2_FONT_SECTION("u8g2_font_lubI24_tr");
extern const uint8_t u8g2_font_lubI24_tn[] U8G2_FONT_SECTION("u8g2_font_lubI24_tn");
extern const uint8_t u8g2_font_lubI24_te[] U8G2_FONT_SECTION("u8g2_font_lubI24_te");
extern const uint8_t u8g2_font_luBIS08_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS08_tf");
extern const uint8_t u8g2_font_luBIS08_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS08_tr");
extern const uint8_t u8g2_font_luBIS08_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS08_tn");
extern const uint8_t u8g2_font_luBIS08_te[] U8G2_FONT_SECTION("u8g2_font_luBIS08_te");
extern const uint8_t u8g2_font_luBIS10_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS10_tf");
extern const uint8_t u8g2_font_luBIS10_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS10_tr");
extern const uint8_t u8g2_font_luBIS10_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS10_tn");
extern const uint8_t u8g2_font_luBIS10_te[] U8G2_FONT_SECTION("u8g2_font_luBIS10_te");
extern const uint8_t u8g2_font_luBIS12_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS12_tf");
extern const uint8_t u8g2_font_luBIS12_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS12_tr");
extern const uint8_t u8g2_font_luBIS12_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS12_tn");
extern const uint8_t u8g2_font_luBIS12_te[] U8G2_FONT_SECTION("u8g2_font_luBIS12_te");
extern const uint8_t u8g2_font_luBIS14_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS14_tf");
extern const uint8_t u8g2_font_luBIS14_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS14_tr");
extern const uint8_t u8g2_font_luBIS14_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS14_tn");
extern const uint8_t u8g2_font_luBIS14_te[] U8G2_FONT_SECTION("u8g2_font_luBIS14_te");
extern const uint8_t u8g2_font_luBIS18_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS18_tf");
extern const uint8_t u8g2_font_luBIS18_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS18_tr");
extern const uint8_t u8g2_font_luBIS18_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS18_tn");
extern const uint8_t u8g2_font_luBIS18_te[] U8G2_FONT_SECTION("u8g2_font_luBIS18_te");
extern const uint8_t u8g2_font_luBIS19_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS19_tf");
extern const uint8_t u8g2_font_luBIS19_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS19_tr");
extern const uint8_t u8g2_font_luBIS19_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS19_tn");
extern const uint8_t u8g2_font_luBIS19_te[] U8G2_FONT_SECTION("u8g2_font_luBIS19_te");
extern const uint8_t u8g2_font_luBIS24_tf[] U8G2_FONT_SECTION("u8g2_font_luBIS24_tf");
extern const uint8_t u8g2_font_luBIS24_tr[] U8G2_FONT_SECTION("u8g2_font_luBIS24_tr");
extern const uint8_t u8g2_font_luBIS24_tn[] U8G2_FONT_SECTION("u8g2_font_luBIS24_tn");
extern const uint8_t u8g2_font_luBIS24_te[] U8G2_FONT_SECTION("u8g2_font_luBIS24_te");
extern const uint8_t u8g2_font_lubR08_tf[] U8G2_FONT_SECTION("u8g2_font_lubR08_tf");
extern const uint8_t u8g2_font_lubR08_tr[] U8G2_FONT_SECTION("u8g2_font_lubR08_tr");
extern const uint8_t u8g2_font_lubR08_tn[] U8G2_FONT_SECTION("u8g2_font_lubR08_tn");
extern const uint8_t u8g2_font_lubR08_te[] U8G2_FONT_SECTION("u8g2_font_lubR08_te");
extern const uint8_t u8g2_font_lubR10_tf[] U8G2_FONT_SECTION("u8g2_font_lubR10_tf");
extern const uint8_t u8g2_font_lubR10_tr[] U8G2_FONT_SECTION("u8g2_font_lubR10_tr");
extern const uint8_t u8g2_font_lubR10_tn[] U8G2_FONT_SECTION("u8g2_font_lubR10_tn");
extern const uint8_t u8g2_font_lubR10_te[] U8G2_FONT_SECTION("u8g2_font_lubR10_te");
extern const uint8_t u8g2_font_lubR12_tf[] U8G2_FONT_SECTION("u8g2_font_lubR12_tf");
extern const uint8_t u8g2_font_lubR12_tr[] U8G2_FONT_SECTION("u8g2_font_lubR12_tr");
extern const uint8_t u8g2_font_lubR12_tn[] U8G2_FONT_SECTION("u8g2_font_lubR12_tn");
extern const uint8_t u8g2_font_lubR12_te[] U8G2_FONT_SECTION("u8g2_font_lubR12_te");
extern const uint8_t u8g2_font_lubR14_tf[] U8G2_FONT_SECTION("u8g2_font_lubR14_tf");
extern const uint8_t u8g2_font_lubR14_tr[] U8G2_FONT_SECTION("u8g2_font_lubR14_tr");
extern const uint8_t u8g2_font_lubR14_tn[] U8G2_FONT_SECTION("u8g2_font_lubR14_tn");
extern const uint8_t u8g2_font_lubR14_te[] U8G2_FONT_SECTION("u8g2_font_lubR14_te");
extern const uint8_t u8g2_font_lubR18_tf[] U8G2_FONT_SECTION("u8g2_font_lubR18_tf");
extern const uint8_t u8g2_font_lubR18_tr[] U8G2_FONT_SECTION("u8g2_font_lubR18_tr");
extern const uint8_t u8g2_font_lubR18_tn[] U8G2_FONT_SECTION("u8g2_font_lubR18_tn");
extern const uint8_t u8g2_font_lubR18_te[] U8G2_FONT_SECTION("u8g2_font_lubR18_te");
extern const uint8_t u8g2_font_lubR19_tf[] U8G2_FONT_SECTION("u8g2_font_lubR19_tf");
extern const uint8_t u8g2_font_lubR19_tr[] U8G2_FONT_SECTION("u8g2_font_lubR19_tr");
extern const uint8_t u8g2_font_lubR19_tn[] U8G2_FONT_SECTION("u8g2_font_lubR19_tn");
extern const uint8_t u8g2_font_lubR19_te[] U8G2_FONT_SECTION("u8g2_font_lubR19_te");
extern const uint8_t u8g2_font_lubR24_tf[] U8G2_FONT_SECTION("u8g2_font_lubR24_tf");
extern const uint8_t u8g2_font_lubR24_tr[] U8G2_FONT_SECTION("u8g2_font_lubR24_tr");
extern const uint8_t u8g2_font_lubR24_tn[] U8G2_FONT_SECTION("u8g2_font_lubR24_tn");
extern const uint8_t u8g2_font_lubR24_te[] U8G2_FONT_SECTION("u8g2_font_lubR24_te");
extern const uint8_t u8g2_font_luBS08_tf[] U8G2_FONT_SECTION("u8g2_font_luBS08_tf");
extern const uint8_t u8g2_font_luBS08_tr[] U8G2_FONT_SECTION("u8g2_font_luBS08_tr");
extern const uint8_t u8g2_font_luBS08_tn[] U8G2_FONT_SECTION("u8g2_font_luBS08_tn");
extern const uint8_t u8g2_font_luBS08_te[] U8G2_FONT_SECTION("u8g2_font_luBS08_te");
extern const uint8_t u8g2_font_luBS10_tf[] U8G2_FONT_SECTION("u8g2_font_luBS10_tf");
extern const uint8_t u8g2_font_luBS10_tr[] U8G2_FONT_SECTION("u8g2_font_luBS10_tr");
extern const uint8_t u8g2_font_luBS10_tn[] U8G2_FONT_SECTION("u8g2_font_luBS10_tn");
extern const uint8_t u8g2_font_luBS10_te[] U8G2_FONT_SECTION("u8g2_font_luBS10_te");
extern const uint8_t u8g2_font_luBS12_tf[] U8G2_FONT_SECTION("u8g2_font_luBS12_tf");
extern const uint8_t u8g2_font_luBS12_tr[] U8G2_FONT_SECTION("u8g2_font_luBS12_tr");
extern const uint8_t u8g2_font_luBS12_tn[] U8G2_FONT_SECTION("u8g2_font_luBS12_tn");
extern const uint8_t u8g2_font_luBS12_te[] U8G2_FONT_SECTION("u8g2_font_luBS12_te");
extern const uint8_t u8g2_font_luBS14_tf[] U8G2_FONT_SECTION("u8g2_font_luBS14_tf");
extern const uint8_t u8g2_font_luBS14_tr[] U8G2_FONT_SECTION("u8g2_font_luBS14_tr");
extern const uint8_t u8g2_font_luBS14_tn[] U8G2_FONT_SECTION("u8g2_font_luBS14_tn");
extern const uint8_t u8g2_font_luBS14_te[] U8G2_FONT_SECTION("u8g2_font_luBS14_te");
extern const uint8_t u8g2_font_luBS18_tf[] U8G2_FONT_SECTION("u8g2_font_luBS18_tf");
extern const uint8_t u8g2_font_luBS18_tr[] U8G2_FONT_SECTION("u8g2_font_luBS18_tr");
extern const uint8_t u8g2_font_luBS18_tn[] U8G2_FONT_SECTION("u8g2_font_luBS18_tn");
extern const uint8_t u8g2_font_luBS18_te[] U8G2_FONT_SECTION("u8g2_font_luBS18_te");
extern const uint8_t u8g2_font_luBS19_tf[] U8G2_FONT_SECTION("u8g2_font_luBS19_tf");
extern const uint8_t u8g2_font_luBS19_tr[] U8G2_FONT_SECTION("u8g2_font_luBS19_tr");
extern const uint8_t u8g2_font_luBS19_tn[] U8G2_FONT_SECTION("u8g2_font_luBS19_tn");
extern const uint8_t u8g2_font_luBS19_te[] U8G2_FONT_SECTION("u8g2_font_luBS19_te");
extern const uint8_t u8g2_font_luBS24_tf[] U8G2_FONT_SECTION("u8g2_font_luBS24_tf");
extern const uint8_t u8g2_font_luBS24_tr[] U8G2_FONT_SECTION("u8g2_font_luBS24_tr");
extern const uint8_t u8g2_font_luBS24_tn[] U8G2_FONT_SECTION("u8g2_font_luBS24_tn");
extern const uint8_t u8g2_font_luBS24_te[] U8G2_FONT_SECTION("u8g2_font_luBS24_te");
extern const uint8_t u8g2_font_luIS08_tf[] U8G2_FONT_SECTION("u8g2_font_luIS08_tf");
extern const uint8_t u8g2_font_luIS08_tr[] U8G2_FONT_SECTION("u8g2_font_luIS08_tr");
extern const uint8_t u8g2_font_luIS08_tn[] U8G2_FONT_SECTION("u8g2_font_luIS08_tn");
extern const uint8_t u8g2_font_luIS08_te[] U8G2_FONT_SECTION("u8g2_font_luIS08_te");
extern const uint8_t u8g2_font_luIS10_tf[] U8G2_FONT_SECTION("u8g2_font_luIS10_tf");
extern const uint8_t u8g2_font_luIS10_tr[] U8G2_FONT_SECTION("u8g2_font_luIS10_tr");
extern const uint8_t u8g2_font_luIS10_tn[] U8G2_FONT_SECTION("u8g2_font_luIS10_tn");
extern const uint8_t u8g2_font_luIS10_te[] U8G2_FONT_SECTION("u8g2_font_luIS10_te");
extern const uint8_t u8g2_font_luIS12_tf[] U8G2_FONT_SECTION("u8g2_font_luIS12_tf");
extern const uint8_t u8g2_font_luIS12_tr[] U8G2_FONT_SECTION("u8g2_font_luIS12_tr");
extern const uint8_t u8g2_font_luIS12_tn[] U8G2_FONT_SECTION("u8g2_font_luIS12_tn");
extern const uint8_t u8g2_font_luIS12_te[] U8G2_FONT_SECTION("u8g2_font_luIS12_te");
extern const uint8_t u8g2_font_luIS14_tf[] U8G2_FONT_SECTION("u8g2_font_luIS14_tf");
extern const uint8_t u8g2_font_luIS14_tr[] U8G2_FONT_SECTION("u8g2_font_luIS14_tr");
extern const uint8_t u8g2_font_luIS14_tn[] U8G2_FONT_SECTION("u8g2_font_luIS14_tn");
extern const uint8_t u8g2_font_luIS14_te[] U8G2_FONT_SECTION("u8g2_font_luIS14_te");
extern const uint8_t u8g2_font_luIS18_tf[] U8G2_FONT_SECTION("u8g2_font_luIS18_tf");
extern const uint8_t u8g2_font_luIS18_tr[] U8G2_FONT_SECTION("u8g2_font_luIS18_tr");
extern const uint8_t u8g2_font_luIS18_tn[] U8G2_FONT_SECTION("u8g2_font_luIS18_tn");
extern const uint8_t u8g2_font_luIS18_te[] U8G2_FONT_SECTION("u8g2_font_luIS18_te");
extern const uint8_t u8g2_font_luIS19_tf[] U8G2_FONT_SECTION("u8g2_font_luIS19_tf");
extern const uint8_t u8g2_font_luIS19_tr[] U8G2_FONT_SECTION("u8g2_font_luIS19_tr");
extern const uint8_t u8g2_font_luIS19_tn[] U8G2_FONT_SECTION("u8g2_font_luIS19_tn");
extern const uint8_t u8g2_font_luIS19_te[] U8G2_FONT_SECTION("u8g2_font_luIS19_te");
extern const uint8_t u8g2_font_luIS24_tf[] U8G2_FONT_SECTION("u8g2_font_luIS24_tf");
extern const uint8_t u8g2_font_luIS24_tr[] U8G2_FONT_SECTION("u8g2_font_luIS24_tr");
extern const uint8_t u8g2_font_luIS24_tn[] U8G2_FONT_SECTION("u8g2_font_luIS24_tn");
extern const uint8_t u8g2_font_luIS24_te[] U8G2_FONT_SECTION("u8g2_font_luIS24_te");
extern const uint8_t u8g2_font_luRS08_tf[] U8G2_FONT_SECTION("u8g2_font_luRS08_tf");
extern const uint8_t u8g2_font_luRS08_tr[] U8G2_FONT_SECTION("u8g2_font_luRS08_tr");
extern const uint8_t u8g2_font_luRS08_tn[] U8G2_FONT_SECTION("u8g2_font_luRS08_tn");
extern const uint8_t u8g2_font_luRS08_te[] U8G2_FONT_SECTION("u8g2_font_luRS08_te");
extern const uint8_t u8g2_font_luRS10_tf[] U8G2_FONT_SECTION("u8g2_font_luRS10_tf");
extern const uint8_t u8g2_font_luRS10_tr[] U8G2_FONT_SECTION("u8g2_font_luRS10_tr");
extern const uint8_t u8g2_font_luRS10_tn[] U8G2_FONT_SECTION("u8g2_font_luRS10_tn");
extern const uint8_t u8g2_font_luRS10_te[] U8G2_FONT_SECTION("u8g2_font_luRS10_te");
extern const uint8_t u8g2_font_luRS12_tf[] U8G2_FONT_SECTION("u8g2_font_luRS12_tf");
extern const uint8_t u8g2_font_luRS12_tr[] U8G2_FONT_SECTION("u8g2_font_luRS12_tr");
extern const uint8_t u8g2_font_luRS12_tn[] U8G2_FONT_SECTION("u8g2_font_luRS12_tn");
extern const uint8_t u8g2_font_luRS12_te[] U8G2_FONT_SECTION("u8g2_font_luRS12_te");
extern const uint8_t u8g2_font_luRS14_tf[] U8G2_FONT_SECTION("u8g2_font_luRS14_tf");
extern const uint8_t u8g2_font_luRS14_tr[] U8G2_FONT_SECTION("u8g2_font_luRS14_tr");
extern const uint8_t u8g2_font_luRS14_tn[] U8G2_FONT_SECTION("u8g2_font_luRS14_tn");
extern const uint8_t u8g2_font_luRS14_te[] U8G2_FONT_SECTION("u8g2_font_luRS14_te");
extern const uint8_t u8g2_font_luRS18_tf[] U8G2_FONT_SECTION("u8g2_font_luRS18_tf");
extern const uint8_t u8g2_font_luRS18_tr[] U8G2_FONT_SECTION("u8g2_font_luRS18_tr");
extern const uint8_t u8g2_font_luRS18_tn[] U8G2_FONT_SECTION("u8g2_font_luRS18_tn");
extern const uint8_t u8g2_font_luRS18_te[] U8G2_FONT_SECTION("u8g2_font_luRS18_te");
extern const uint8_t u8g2_font_luRS19_tf[] U8G2_FONT_SECTION("u8g2_font_luRS19_tf");
extern const uint8_t u8g2_font_luRS19_tr[] U8G2_FONT_SECTION("u8g2_font_luRS19_tr");
extern const uint8_t u8g2_font_luRS19_tn[] U8G2_FONT_SECTION("u8g2_font_luRS19_tn");
extern const uint8_t u8g2_font_luRS19_te[] U8G2_FONT_SECTION("u8g2_font_luRS19_te");
extern const uint8_t u8g2_font_luRS24_tf[] U8G2_FONT_SECTION("u8g2_font_luRS24_tf");
extern const uint8_t u8g2_font_luRS24_tr[] U8G2_FONT_SECTION("u8g2_font_luRS24_tr");
extern const uint8_t u8g2_font_luRS24_tn[] U8G2_FONT_SECTION("u8g2_font_luRS24_tn");
extern const uint8_t u8g2_font_luRS24_te[] U8G2_FONT_SECTION("u8g2_font_luRS24_te");
extern const uint8_t u8g2_font_baby_tf[] U8G2_FONT_SECTION("u8g2_font_baby_tf");
extern const uint8_t u8g2_font_baby_tr[] U8G2_FONT_SECTION("u8g2_font_baby_tr");
extern const uint8_t u8g2_font_baby_tn[] U8G2_FONT_SECTION("u8g2_font_baby_tn");
extern const uint8_t u8g2_font_blipfest_07_tr[] U8G2_FONT_SECTION("u8g2_font_blipfest_07_tr");
extern const uint8_t u8g2_font_blipfest_07_tn[] U8G2_FONT_SECTION("u8g2_font_blipfest_07_tn");
extern const uint8_t u8g2_font_chikita_tf[] U8G2_FONT_SECTION("u8g2_font_chikita_tf");
extern const uint8_t u8g2_font_chikita_tr[] U8G2_FONT_SECTION("u8g2_font_chikita_tr");
extern const uint8_t u8g2_font_chikita_tn[] U8G2_FONT_SECTION("u8g2_font_chikita_tn");
extern const uint8_t u8g2_font_lucasfont_alternate_tf[] U8G2_FONT_SECTION("u8g2_font_lucasfont_alternate_tf");
extern const uint8_t u8g2_font_lucasfont_alternate_tr[] U8G2_FONT_SECTION("u8g2_font_lucasfont_alternate_tr");
extern const uint8_t u8g2_font_lucasfont_alternate_tn[] U8G2_FONT_SECTION("u8g2_font_lucasfont_alternate_tn");
extern const uint8_t u8g2_font_p01type_tf[] U8G2_FONT_SECTION("u8g2_font_p01type_tf");
extern const uint8_t u8g2_font_p01type_tr[] U8G2_FONT_SECTION("u8g2_font_p01type_tr");
extern const uint8_t u8g2_font_p01type_tn[] U8G2_FONT_SECTION("u8g2_font_p01type_tn");
extern const uint8_t u8g2_font_pixelle_micro_tr[] U8G2_FONT_SECTION("u8g2_font_pixelle_micro_tr");
extern const uint8_t u8g2_font_pixelle_micro_tn[] U8G2_FONT_SECTION("u8g2_font_pixelle_micro_tn");
extern const uint8_t u8g2_font_robot_de_niro_tf[] U8G2_FONT_SECTION("u8g2_font_robot_de_niro_tf");
extern const uint8_t u8g2_font_robot_de_niro_tr[] U8G2_FONT_SECTION("u8g2_font_robot_de_niro_tr");
extern const uint8_t u8g2_font_robot_de_niro_tn[] U8G2_FONT_SECTION("u8g2_font_robot_de_niro_tn");
extern const uint8_t u8g2_font_trixel_square_tf[] U8G2_FONT_SECTION("u8g2_font_trixel_square_tf");
extern const uint8_t u8g2_font_trixel_square_tr[] U8G2_FONT_SECTION("u8g2_font_trixel_square_tr");
extern const uint8_t u8g2_font_trixel_square_tn[] U8G2_FONT_SECTION("u8g2_font_trixel_square_tn");
extern const uint8_t u8g2_font_haxrcorp4089_tr[] U8G2_FONT_SECTION("u8g2_font_haxrcorp4089_tr");
extern const uint8_t u8g2_font_haxrcorp4089_tn[] U8G2_FONT_SECTION("u8g2_font_haxrcorp4089_tn");
extern const uint8_t u8g2_font_haxrcorp4089_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_haxrcorp4089_t_cyrillic");
extern const uint8_t u8g2_font_bubble_tr[] U8G2_FONT_SECTION("u8g2_font_bubble_tr");
extern const uint8_t u8g2_font_bubble_tn[] U8G2_FONT_SECTION("u8g2_font_bubble_tn");
extern const uint8_t u8g2_font_cardimon_pixel_tf[] U8G2_FONT_SECTION("u8g2_font_cardimon_pixel_tf");
extern const uint8_t u8g2_font_cardimon_pixel_tr[] U8G2_FONT_SECTION("u8g2_font_cardimon_pixel_tr");
extern const uint8_t u8g2_font_cardimon_pixel_tn[] U8G2_FONT_SECTION("u8g2_font_cardimon_pixel_tn");
extern const uint8_t u8g2_font_maniac_tf[] U8G2_FONT_SECTION("u8g2_font_maniac_tf");
extern const uint8_t u8g2_font_maniac_tr[] U8G2_FONT_SECTION("u8g2_font_maniac_tr");
extern const uint8_t u8g2_font_maniac_tn[] U8G2_FONT_SECTION("u8g2_font_maniac_tn");
extern const uint8_t u8g2_font_maniac_te[] U8G2_FONT_SECTION("u8g2_font_maniac_te");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_o_tf[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_o_tf");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_o_tr[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_o_tr");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_o_tn[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_o_tn");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_r_tf[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_r_tf");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_r_tr[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_r_tr");
extern const uint8_t u8g2_font_lucasarts_scumm_subtitle_r_tn[] U8G2_FONT_SECTION("u8g2_font_lucasarts_scumm_subtitle_r_tn");
extern const uint8_t u8g2_font_utopia24_tf[] U8G2_FONT_SECTION("u8g2_font_utopia24_tf");
extern const uint8_t u8g2_font_utopia24_tr[] U8G2_FONT_SECTION("u8g2_font_utopia24_tr");
extern const uint8_t u8g2_font_utopia24_tn[] U8G2_FONT_SECTION("u8g2_font_utopia24_tn");
extern const uint8_t u8g2_font_utopia24_te[] U8G2_FONT_SECTION("u8g2_font_utopia24_te");
extern const uint8_t u8g2_font_m_c_kids_nes_credits_font_tr[] U8G2_FONT_SECTION("u8g2_font_m_c_kids_nes_credits_font_tr");
extern const uint8_t u8g2_font_chargen_92_tf[] U8G2_FONT_SECTION("u8g2_font_chargen_92_tf");
extern const uint8_t u8g2_font_chargen_92_tr[] U8G2_FONT_SECTION("u8g2_font_chargen_92_tr");
extern const uint8_t u8g2_font_chargen_92_tn[] U8G2_FONT_SECTION("u8g2_font_chargen_92_tn");
extern const uint8_t u8g2_font_chargen_92_te[] U8G2_FONT_SECTION("u8g2_font_chargen_92_te");
extern const uint8_t u8g2_font_chargen_92_mf[] U8G2_FONT_SECTION("u8g2_font_chargen_92_mf");
extern const uint8_t u8g2_font_chargen_92_mr[] U8G2_FONT_SECTION("u8g2_font_chargen_92_mr");
extern const uint8_t u8g2_font_chargen_92_mn[] U8G2_FONT_SECTION("u8g2_font_chargen_92_mn");
extern const uint8_t u8g2_font_chargen_92_me[] U8G2_FONT_SECTION("u8g2_font_chargen_92_me");
extern const uint8_t u8g2_font_fub11_tf[] U8G2_FONT_SECTION("u8g2_font_fub11_tf");
extern const uint8_t u8g2_font_fub11_tr[] U8G2_FONT_SECTION("u8g2_font_fub11_tr");
extern const uint8_t u8g2_font_fub11_tn[] U8G2_FONT_SECTION("u8g2_font_fub11_tn");
extern const uint8_t u8g2_font_fub14_tf[] U8G2_FONT_SECTION("u8g2_font_fub14_tf");
extern const uint8_t u8g2_font_fub14_tr[] U8G2_FONT_SECTION("u8g2_font_fub14_tr");
extern const uint8_t u8g2_font_fub14_tn[] U8G2_FONT_SECTION("u8g2_font_fub14_tn");
extern const uint8_t u8g2_font_fub17_tf[] U8G2_FONT_SECTION("u8g2_font_fub17_tf");
extern const uint8_t u8g2_font_fub17_tr[] U8G2_FONT_SECTION("u8g2_font_fub17_tr");
extern const uint8_t u8g2_font_fub17_tn[] U8G2_FONT_SECTION("u8g2_font_fub17_tn");
extern const uint8_t u8g2_font_fub20_tf[] U8G2_FONT_SECTION("u8g2_font_fub20_tf");
extern const uint8_t u8g2_font_fub20_tr[] U8G2_FONT_SECTION("u8g2_font_fub20_tr");
extern const uint8_t u8g2_font_fub20_tn[] U8G2_FONT_SECTION("u8g2_font_fub20_tn");
extern const uint8_t u8g2_font_fub25_tf[] U8G2_FONT_SECTION("u8g2_font_fub25_tf");
extern const uint8_t u8g2_font_fub25_tr[] U8G2_FONT_SECTION("u8g2_font_fub25_tr");
extern const uint8_t u8g2_font_fub25_tn[] U8G2_FONT_SECTION("u8g2_font_fub25_tn");
extern const uint8_t u8g2_font_fub30_tf[] U8G2_FONT_SECTION("u8g2_font_fub30_tf");
extern const uint8_t u8g2_font_fub30_tr[] U8G2_FONT_SECTION("u8g2_font_fub30_tr");
extern const uint8_t u8g2_font_fub30_tn[] U8G2_FONT_SECTION("u8g2_font_fub30_tn");
extern const uint8_t u8g2_font_fub35_tf[] U8G2_FONT_SECTION("u8g2_font_fub35_tf");
extern const uint8_t u8g2_font_fub35_tr[] U8G2_FONT_SECTION("u8g2_font_fub35_tr");
extern const uint8_t u8g2_font_fub35_tn[] U8G2_FONT_SECTION("u8g2_font_fub35_tn");
extern const uint8_t u8g2_font_fub42_tf[] U8G2_FONT_SECTION("u8g2_font_fub42_tf");
extern const uint8_t u8g2_font_fub42_tr[] U8G2_FONT_SECTION("u8g2_font_fub42_tr");
extern const uint8_t u8g2_font_fub42_tn[] U8G2_FONT_SECTION("u8g2_font_fub42_tn");
extern const uint8_t u8g2_font_fub49_tn[] U8G2_FONT_SECTION("u8g2_font_fub49_tn");
extern const uint8_t u8g2_font_fub11_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub11_t_symbol");
extern const uint8_t u8g2_font_fub14_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub14_t_symbol");
extern const uint8_t u8g2_font_fub17_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub17_t_symbol");
extern const uint8_t u8g2_font_fub20_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub20_t_symbol");
extern const uint8_t u8g2_font_fub25_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub25_t_symbol");
extern const uint8_t u8g2_font_fub30_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub30_t_symbol");
extern const uint8_t u8g2_font_fub35_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub35_t_symbol");
extern const uint8_t u8g2_font_fub42_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub42_t_symbol");
extern const uint8_t u8g2_font_fub49_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fub49_t_symbol");
extern const uint8_t u8g2_font_fur11_tf[] U8G2_FONT_SECTION("u8g2_font_fur11_tf");
extern const uint8_t u8g2_font_fur11_tr[] U8G2_FONT_SECTION("u8g2_font_fur11_tr");
extern const uint8_t u8g2_font_fur11_tn[] U8G2_FONT_SECTION("u8g2_font_fur11_tn");
extern const uint8_t u8g2_font_fur14_tf[] U8G2_FONT_SECTION("u8g2_font_fur14_tf");
extern const uint8_t u8g2_font_fur14_tr[] U8G2_FONT_SECTION("u8g2_font_fur14_tr");
extern const uint8_t u8g2_font_fur14_tn[] U8G2_FONT_SECTION("u8g2_font_fur14_tn");
extern const uint8_t u8g2_font_fur17_tf[] U8G2_FONT_SECTION("u8g2_font_fur17_tf");
extern const uint8_t u8g2_font_fur17_tr[] U8G2_FONT_SECTION("u8g2_font_fur17_tr");
extern const uint8_t u8g2_font_fur17_tn[] U8G2_FONT_SECTION("u8g2_font_fur17_tn");
extern const uint8_t u8g2_font_fur20_tf[] U8G2_FONT_SECTION("u8g2_font_fur20_tf");
extern const uint8_t u8g2_font_fur20_tr[] U8G2_FONT_SECTION("u8g2_font_fur20_tr");
extern const uint8_t u8g2_font_fur20_tn[] U8G2_FONT_SECTION("u8g2_font_fur20_tn");
extern const uint8_t u8g2_font_fur25_tf[] U8G2_FONT_SECTION("u8g2_font_fur25_tf");
extern const uint8_t u8g2_font_fur25_tr[] U8G2_FONT_SECTION("u8g2_font_fur25_tr");
extern const uint8_t u8g2_font_fur25_tn[] U8G2_FONT_SECTION("u8g2_font_fur25_tn");
extern const uint8_t u8g2_font_fur30_tf[] U8G2_FONT_SECTION("u8g2_font_fur30_tf");
extern const uint8_t u8g2_font_fur30_tr[] U8G2_FONT_SECTION("u8g2_font_fur30_tr");
extern const uint8_t u8g2_font_fur30_tn[] U8G2_FONT_SECTION("u8g2_font_fur30_tn");
extern const uint8_t u8g2_font_fur35_tf[] U8G2_FONT_SECTION("u8g2_font_fur35_tf");
extern const uint8_t u8g2_font_fur35_tr[] U8G2_FONT_SECTION("u8g2_font_fur35_tr");
extern const uint8_t u8g2_font_fur35_tn[] U8G2_FONT_SECTION("u8g2_font_fur35_tn");
extern const uint8_t u8g2_font_fur42_tf[] U8G2_FONT_SECTION("u8g2_font_fur42_tf");
extern const uint8_t u8g2_font_fur42_tr[] U8G2_FONT_SECTION("u8g2_font_fur42_tr");
extern const uint8_t u8g2_font_fur42_tn[] U8G2_FONT_SECTION("u8g2_font_fur42_tn");
extern const uint8_t u8g2_font_fur49_tn[] U8G2_FONT_SECTION("u8g2_font_fur49_tn");
extern const uint8_t u8g2_font_fur11_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur11_t_symbol");
extern const uint8_t u8g2_font_fur14_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur14_t_symbol");
extern const uint8_t u8g2_font_fur17_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur17_t_symbol");
extern const uint8_t u8g2_font_fur20_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur20_t_symbol");
extern const uint8_t u8g2_font_fur25_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur25_t_symbol");
extern const uint8_t u8g2_font_fur30_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur30_t_symbol");
extern const uint8_t u8g2_font_fur35_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur35_t_symbol");
extern const uint8_t u8g2_font_fur42_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur42_t_symbol");
extern const uint8_t u8g2_font_fur49_t_symbol[] U8G2_FONT_SECTION("u8g2_font_fur49_t_symbol");
extern const uint8_t u8g2_font_osb18_tf[] U8G2_FONT_SECTION("u8g2_font_osb18_tf");
extern const uint8_t u8g2_font_osb18_tr[] U8G2_FONT_SECTION("u8g2_font_osb18_tr");
extern const uint8_t u8g2_font_osb18_tn[] U8G2_FONT_SECTION("u8g2_font_osb18_tn");
extern const uint8_t u8g2_font_osb21_tf[] U8G2_FONT_SECTION("u8g2_font_osb21_tf");
extern const uint8_t u8g2_font_osb21_tr[] U8G2_FONT_SECTION("u8g2_font_osb21_tr");
extern const uint8_t u8g2_font_osb21_tn[] U8G2_FONT_SECTION("u8g2_font_osb21_tn");
extern const uint8_t u8g2_font_osb26_tf[] U8G2_FONT_SECTION("u8g2_font_osb26_tf");
extern const uint8_t u8g2_font_osb26_tr[] U8G2_FONT_SECTION("u8g2_font_osb26_tr");
extern const uint8_t u8g2_font_osb26_tn[] U8G2_FONT_SECTION("u8g2_font_osb26_tn");
extern const uint8_t u8g2_font_osb29_tf[] U8G2_FONT_SECTION("u8g2_font_osb29_tf");
extern const uint8_t u8g2_font_osb29_tr[] U8G2_FONT_SECTION("u8g2_font_osb29_tr");
extern const uint8_t u8g2_font_osb29_tn[] U8G2_FONT_SECTION("u8g2_font_osb29_tn");
extern const uint8_t u8g2_font_osb35_tf[] U8G2_FONT_SECTION("u8g2_font_osb35_tf");
extern const uint8_t u8g2_font_osb35_tr[] U8G2_FONT_SECTION("u8g2_font_osb35_tr");
extern const uint8_t u8g2_font_osb35_tn[] U8G2_FONT_SECTION("u8g2_font_osb35_tn");
extern const uint8_t u8g2_font_osb41_tf[] U8G2_FONT_SECTION("u8g2_font_osb41_tf");
extern const uint8_t u8g2_font_osb41_tr[] U8G2_FONT_SECTION("u8g2_font_osb41_tr");
extern const uint8_t u8g2_font_osb41_tn[] U8G2_FONT_SECTION("u8g2_font_osb41_tn");
extern const uint8_t u8g2_font_osr18_tf[] U8G2_FONT_SECTION("u8g2_font_osr18_tf");
extern const uint8_t u8g2_font_osr18_tr[] U8G2_FONT_SECTION("u8g2_font_osr18_tr");
extern const uint8_t u8g2_font_osr18_tn[] U8G2_FONT_SECTION("u8g2_font_osr18_tn");
extern const uint8_t u8g2_font_osr21_tf[] U8G2_FONT_SECTION("u8g2_font_osr21_tf");
extern const uint8_t u8g2_font_osr21_tr[] U8G2_FONT_SECTION("u8g2_font_osr21_tr");
extern const uint8_t u8g2_font_osr21_tn[] U8G2_FONT_SECTION("u8g2_font_osr21_tn");
extern const uint8_t u8g2_font_osr26_tf[] U8G2_FONT_SECTION("u8g2_font_osr26_tf");
extern const uint8_t u8g2_font_osr26_tr[] U8G2_FONT_SECTION("u8g2_font_osr26_tr");
extern const uint8_t u8g2_font_osr26_tn[] U8G2_FONT_SECTION("u8g2_font_osr26_tn");
extern const uint8_t u8g2_font_osr29_tf[] U8G2_FONT_SECTION("u8g2_font_osr29_tf");
extern const uint8_t u8g2_font_osr29_tr[] U8G2_FONT_SECTION("u8g2_font_osr29_tr");
extern const uint8_t u8g2_font_osr29_tn[] U8G2_FONT_SECTION("u8g2_font_osr29_tn");
extern const uint8_t u8g2_font_osr35_tf[] U8G2_FONT_SECTION("u8g2_font_osr35_tf");
extern const uint8_t u8g2_font_osr35_tr[] U8G2_FONT_SECTION("u8g2_font_osr35_tr");
extern const uint8_t u8g2_font_osr35_tn[] U8G2_FONT_SECTION("u8g2_font_osr35_tn");
extern const uint8_t u8g2_font_osr41_tf[] U8G2_FONT_SECTION("u8g2_font_osr41_tf");
extern const uint8_t u8g2_font_osr41_tr[] U8G2_FONT_SECTION("u8g2_font_osr41_tr");
extern const uint8_t u8g2_font_osr41_tn[] U8G2_FONT_SECTION("u8g2_font_osr41_tn");
extern const uint8_t u8g2_font_inr16_mf[] U8G2_FONT_SECTION("u8g2_font_inr16_mf");
extern const uint8_t u8g2_font_inr16_mr[] U8G2_FONT_SECTION("u8g2_font_inr16_mr");
extern const uint8_t u8g2_font_inr16_mn[] U8G2_FONT_SECTION("u8g2_font_inr16_mn");
extern const uint8_t u8g2_font_inr19_mf[] U8G2_FONT_SECTION("u8g2_font_inr19_mf");
extern const uint8_t u8g2_font_inr19_mr[] U8G2_FONT_SECTION("u8g2_font_inr19_mr");
extern const uint8_t u8g2_font_inr19_mn[] U8G2_FONT_SECTION("u8g2_font_inr19_mn");
extern const uint8_t u8g2_font_inr21_mf[] U8G2_FONT_SECTION("u8g2_font_inr21_mf");
extern const uint8_t u8g2_font_inr21_mr[] U8G2_FONT_SECTION("u8g2_font_inr21_mr");
extern const uint8_t u8g2_font_inr21_mn[] U8G2_FONT_SECTION("u8g2_font_inr21_mn");
extern const uint8_t u8g2_font_inr24_mf[] U8G2_FONT_SECTION("u8g2_font_inr24_mf");
extern const uint8_t u8g2_font_inr24_mr[] U8G2_FONT_SECTION("u8g2_font_inr24_mr");
extern const uint8_t u8g2_font_inr24_mn[] U8G2_FONT_SECTION("u8g2_font_inr24_mn");
extern const uint8_t u8g2_font_inr24_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr24_t_cyrillic");
extern const uint8_t u8g2_font_inr27_mf[] U8G2_FONT_SECTION("u8g2_font_inr27_mf");
extern const uint8_t u8g2_font_inr27_mr[] U8G2_FONT_SECTION("u8g2_font_inr27_mr");
extern const uint8_t u8g2_font_inr27_mn[] U8G2_FONT_SECTION("u8g2_font_inr27_mn");
extern const uint8_t u8g2_font_inr27_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr27_t_cyrillic");
extern const uint8_t u8g2_font_inr30_mf[] U8G2_FONT_SECTION("u8g2_font_inr30_mf");
extern const uint8_t u8g2_font_inr30_mr[] U8G2_FONT_SECTION("u8g2_font_inr30_mr");
extern const uint8_t u8g2_font_inr30_mn[] U8G2_FONT_SECTION("u8g2_font_inr30_mn");
extern const uint8_t u8g2_font_inr30_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr30_t_cyrillic");
extern const uint8_t u8g2_font_inr33_mf[] U8G2_FONT_SECTION("u8g2_font_inr33_mf");
extern const uint8_t u8g2_font_inr33_mr[] U8G2_FONT_SECTION("u8g2_font_inr33_mr");
extern const uint8_t u8g2_font_inr33_mn[] U8G2_FONT_SECTION("u8g2_font_inr33_mn");
extern const uint8_t u8g2_font_inr33_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr33_t_cyrillic");
extern const uint8_t u8g2_font_inr38_mf[] U8G2_FONT_SECTION("u8g2_font_inr38_mf");
extern const uint8_t u8g2_font_inr38_mr[] U8G2_FONT_SECTION("u8g2_font_inr38_mr");
extern const uint8_t u8g2_font_inr38_mn[] U8G2_FONT_SECTION("u8g2_font_inr38_mn");
extern const uint8_t u8g2_font_inr38_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr38_t_cyrillic");
extern const uint8_t u8g2_font_inr42_mf[] U8G2_FONT_SECTION("u8g2_font_inr42_mf");
extern const uint8_t u8g2_font_inr42_mr[] U8G2_FONT_SECTION("u8g2_font_inr42_mr");
extern const uint8_t u8g2_font_inr42_mn[] U8G2_FONT_SECTION("u8g2_font_inr42_mn");
extern const uint8_t u8g2_font_inr42_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr42_t_cyrillic");
extern const uint8_t u8g2_font_inr46_mf[] U8G2_FONT_SECTION("u8g2_font_inr46_mf");
extern const uint8_t u8g2_font_inr46_mr[] U8G2_FONT_SECTION("u8g2_font_inr46_mr");
extern const uint8_t u8g2_font_inr46_mn[] U8G2_FONT_SECTION("u8g2_font_inr46_mn");
extern const uint8_t u8g2_font_inr46_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr46_t_cyrillic");
extern const uint8_t u8g2_font_inr49_mf[] U8G2_FONT_SECTION("u8g2_font_inr49_mf");
extern const uint8_t u8g2_font_inr49_mr[] U8G2_FONT_SECTION("u8g2_font_inr49_mr");
extern const uint8_t u8g2_font_inr49_mn[] U8G2_FONT_SECTION("u8g2_font_inr49_mn");
extern const uint8_t u8g2_font_inr49_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr49_t_cyrillic");
extern const uint8_t u8g2_font_inr53_mf[] U8G2_FONT_SECTION("u8g2_font_inr53_mf");
extern const uint8_t u8g2_font_inr53_mr[] U8G2_FONT_SECTION("u8g2_font_inr53_mr");
extern const uint8_t u8g2_font_inr53_mn[] U8G2_FONT_SECTION("u8g2_font_inr53_mn");
extern const uint8_t u8g2_font_inr53_t_cyrillic[] U8G2_FONT_SECTION("u8g2_font_inr53_t_cyrillic");
extern const uint8_t u8g2_font_inr57_mn[] U8G2_FONT_SECTION("u8g2_font_inr57_mn");
extern const uint8_t u8g2_font_inr62_mn[] U8G2_FONT_SECTION("u8g2_font_inr62_mn");
extern const uint8_t u8g2_font_inb16_mf[] U8G2_FONT_SECTION("u8g2_font_inb16_mf");
extern const uint8_t u8g2_font_inb16_mr[] U8G2_FONT_SECTION("u8g2_font_inb16_mr");
extern const uint8_t u8g2_font_inb16_mn[] U8G2_FONT_SECTION("u8g2_font_inb16_mn");
extern const uint8_t u8g2_font_inb19_mf[] U8G2_FONT_SECTION("u8g2_font_inb19_mf");
extern const uint8_t u8g2_font_inb19_mr[] U8G2_FONT_SECTION("u8g2_font_inb19_mr");
extern const uint8_t u8g2_font_inb19_mn[] U8G2_FONT_SECTION("u8g2_font_inb19_mn");
extern const uint8_t u8g2_font_inb21_mf[] U8G2_FONT_SECTION("u8g2_font_inb21_mf");
extern const uint8_t u8g2_font_inb21_mr[] U8G2_FONT_SECTION("u8g2_font_inb21_mr");
extern const uint8_t u8g2_font_inb21_mn[] U8G2_FONT_SECTION("u8g2_font_inb21_mn");
extern const uint8_t u8g2_font_inb24_mf[] U8G2_FONT_SECTION("u8g2_font_inb24_mf");
extern const uint8_t u8g2_font_inb24_mr[] U8G2_FONT_SECTION("u8g2_font_inb24_mr");
extern const uint8_t u8g2_font_inb24_mn[] U8G2_FONT_SECTION("u8g2_font_inb24_mn");
extern const uint8_t u8g2_font_inb27_mf[] U8G2_FONT_SECTION("u8g2_font_inb27_mf");
extern const uint8_t u8g2_font_inb27_mr[] U8G2_FONT_SECTION("u8g2_font_inb27_mr");
extern const uint8_t u8g2_font_inb27_mn[] U8G2_FONT_SECTION("u8g2_font_inb27_mn");
extern const uint8_t u8g2_font_inb30_mf[] U8G2_FONT_SECTION("u8g2_font_inb30_mf");
extern const uint8_t u8g2_font_inb30_mr[] U8G2_FONT_SECTION("u8g2_font_inb30_mr");
extern const uint8_t u8g2_font_inb30_mn[] U8G2_FONT_SECTION("u8g2_font_inb30_mn");
extern const uint8_t u8g2_font_inb33_mf[] U8G2_FONT_SECTION("u8g2_font_inb33_mf");
extern const uint8_t u8g2_font_inb33_mr[] U8G2_FONT_SECTION("u8g2_font_inb33_mr");
extern const uint8_t u8g2_font_inb33_mn[] U8G2_FONT_SECTION("u8g2_font_inb33_mn");
extern const uint8_t u8g2_font_inb38_mf[] U8G2_FONT_SECTION("u8g2_font_inb38_mf");
extern const uint8_t u8g2_font_inb38_mr[] U8G2_FONT_SECTION("u8g2_font_inb38_mr");
extern const uint8_t u8g2_font_inb38_mn[] U8G2_FONT_SECTION("u8g2_font_inb38_mn");
extern const uint8_t u8g2_font_inb42_mf[] U8G2_FONT_SECTION("u8g2_font_inb42_mf");
extern const uint8_t u8g2_font_inb42_mr[] U8G2_FONT_SECTION("u8g2_font_inb42_mr");
extern const uint8_t u8g2_font_inb42_mn[] U8G2_FONT_SECTION("u8g2_font_inb42_mn");
extern const uint8_t u8g2_font_inb46_mf[] U8G2_FONT_SECTION("u8g2_font_inb46_mf");
extern const uint8_t u8g2_font_inb46_mr[] U8G2_FONT_SECTION("u8g2_font_inb46_mr");
extern const uint8_t u8g2_font_inb46_mn[] U8G2_FONT_SECTION("u8g2_font_inb46_mn");
extern const uint8_t u8g2_font_inb49_mf[] U8G2_FONT_SECTION("u8g2_font_inb49_mf");
extern const uint8_t u8g2_font_inb49_mr[] U8G2_FONT_SECTION("u8g2_font_inb49_mr");
extern const uint8_t u8g2_font_inb49_mn[] U8G2_FONT_SECTION("u8g2_font_inb49_mn");
extern const uint8_t u8g2_font_inb53_mf[] U8G2_FONT_SECTION("u8g2_font_inb53_mf");
extern const uint8_t u8g2_font_inb53_mr[] U8G2_FONT_SECTION("u8g2_font_inb53_mr");
extern const uint8_t u8g2_font_inb53_mn[] U8G2_FONT_SECTION("u8g2_font_inb53_mn");
extern const uint8_t u8g2_font_inb57_mn[] U8G2_FONT_SECTION("u8g2_font_inb57_mn");
extern const uint8_t u8g2_font_inb63_mn[] U8G2_FONT_SECTION("u8g2_font_inb63_mn");
extern const uint8_t u8g2_font_logisoso16_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso16_tf");
extern const uint8_t u8g2_font_logisoso16_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso16_tr");
extern const uint8_t u8g2_font_logisoso16_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso16_tn");
extern const uint8_t u8g2_font_logisoso18_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso18_tf");
extern const uint8_t u8g2_font_logisoso18_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso18_tr");
extern const uint8_t u8g2_font_logisoso18_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso18_tn");
extern const uint8_t u8g2_font_logisoso20_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso20_tf");
extern const uint8_t u8g2_font_logisoso20_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso20_tr");
extern const uint8_t u8g2_font_logisoso20_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso20_tn");
extern const uint8_t u8g2_font_logisoso22_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso22_tf");
extern const uint8_t u8g2_font_logisoso22_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso22_tr");
extern const uint8_t u8g2_font_logisoso22_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso22_tn");
extern const uint8_t u8g2_font_logisoso24_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso24_tf");
extern const uint8_t u8g2_font_logisoso24_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso24_tr");
extern const uint8_t u8g2_font_logisoso24_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso24_tn");
extern const uint8_t u8g2_font_logisoso26_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso26_tf");
extern const uint8_t u8g2_font_logisoso26_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso26_tr");
extern const uint8_t u8g2_font_logisoso26_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso26_tn");
extern const uint8_t u8g2_font_logisoso28_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso28_tf");
extern const uint8_t u8g2_font_logisoso28_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso28_tr");
extern const uint8_t u8g2_font_logisoso28_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso28_tn");
extern const uint8_t u8g2_font_logisoso30_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso30_tf");
extern const uint8_t u8g2_font_logisoso30_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso30_tr");
extern const uint8_t u8g2_font_logisoso30_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso30_tn");
extern const uint8_t u8g2_font_logisoso32_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso32_tf");
extern const uint8_t u8g2_font_logisoso32_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso32_tr");
extern const uint8_t u8g2_font_logisoso32_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso32_tn");
extern const uint8_t u8g2_font_logisoso34_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso34_tf");
extern const uint8_t u8g2_font_logisoso34_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso34_tr");
extern const uint8_t u8g2_font_logisoso34_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso34_tn");
extern const uint8_t u8g2_font_logisoso38_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso38_tf");
extern const uint8_t u8g2_font_logisoso38_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso38_tr");
extern const uint8_t u8g2_font_logisoso38_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso38_tn");
extern const uint8_t u8g2_font_logisoso42_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso42_tf");
extern const uint8_t u8g2_font_logisoso42_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso42_tr");
extern const uint8_t u8g2_font_logisoso42_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso42_tn");
extern const uint8_t u8g2_font_logisoso46_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso46_tf");
extern const uint8_t u8g2_font_logisoso46_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso46_tr");
extern const uint8_t u8g2_font_logisoso46_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso46_tn");
extern const uint8_t u8g2_font_logisoso50_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso50_tf");
extern const uint8_t u8g2_font_logisoso50_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso50_tr");
extern const uint8_t u8g2_font_logisoso50_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso50_tn");
extern const uint8_t u8g2_font_logisoso54_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso54_tf");
extern const uint8_t u8g2_font_logisoso54_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso54_tr");
extern const uint8_t u8g2_font_logisoso54_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso54_tn");
extern const uint8_t u8g2_font_logisoso58_tf[] U8G2_FONT_SECTION("u8g2_font_logisoso58_tf");
extern const uint8_t u8g2_font_logisoso58_tr[] U8G2_FONT_SECTION("u8g2_font_logisoso58_tr");
extern const uint8_t u8g2_font_logisoso58_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso58_tn");
extern const uint8_t u8g2_font_logisoso62_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso62_tn");
extern const uint8_t u8g2_font_logisoso78_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso78_tn");
extern const uint8_t u8g2_font_logisoso92_tn[] U8G2_FONT_SECTION("u8g2_font_logisoso92_tn");
extern const uint8_t u8g2_font_pressstart2p_8f[] U8G2_FONT_SECTION("u8g2_font_pressstart2p_8f");
extern const uint8_t u8g2_font_pressstart2p_8r[] U8G2_FONT_SECTION("u8g2_font_pressstart2p_8r");
extern const uint8_t u8g2_font_pressstart2p_8n[] U8G2_FONT_SECTION("u8g2_font_pressstart2p_8n");
extern const uint8_t u8g2_font_pressstart2p_8u[] U8G2_FONT_SECTION("u8g2_font_pressstart2p_8u");
extern const uint8_t u8g2_font_pcsenior_8f[] U8G2_FONT_SECTION("u8g2_font_pcsenior_8f");
extern const uint8_t u8g2_font_pcsenior_8r[] U8G2_FONT_SECTION("u8g2_font_pcsenior_8r");
extern const uint8_t u8g2_font_pcsenior_8n[] U8G2_FONT_SECTION("u8g2_font_pcsenior_8n");
extern const uint8_t u8g2_font_pcsenior_8u[] U8G2_FONT_SECTION("u8g2_font_pcsenior_8u");
extern const uint8_t u8g2_font_pxplusibmcgathin_8f[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcgathin_8f");
extern const uint8_t u8g2_font_pxplusibmcgathin_8r[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcgathin_8r");
extern const uint8_t u8g2_font_pxplusibmcgathin_8n[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcgathin_8n");
extern const uint8_t u8g2_font_pxplusibmcgathin_8u[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcgathin_8u");
extern const uint8_t u8g2_font_pxplusibmcga_8f[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcga_8f");
extern const uint8_t u8g2_font_pxplusibmcga_8r[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcga_8r");
extern const uint8_t u8g2_font_pxplusibmcga_8n[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcga_8n");
extern const uint8_t u8g2_font_pxplusibmcga_8u[] U8G2_FONT_SECTION("u8g2_font_pxplusibmcga_8u");
extern const uint8_t u8g2_font_pxplustandynewtv_8f[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_8f");
extern const uint8_t u8g2_font_pxplustandynewtv_8r[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_8r");
extern const uint8_t u8g2_font_pxplustandynewtv_8n[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_8n");
extern const uint8_t u8g2_font_pxplustandynewtv_8u[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_8u");
extern const uint8_t u8g2_font_pxplustandynewtv_t_all[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_t_all");
extern const uint8_t u8g2_font_pxplustandynewtv_8_all[] U8G2_FONT_SECTION("u8g2_font_pxplustandynewtv_8_all");
extern const uint8_t u8g2_font_pxplusibmvga9_tf[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_tf");
extern const uint8_t u8g2_font_pxplusibmvga9_tr[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_tr");
extern const uint8_t u8g2_font_pxplusibmvga9_tn[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_tn");
extern const uint8_t u8g2_font_pxplusibmvga9_mf[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_mf");
extern const uint8_t u8g2_font_pxplusibmvga9_mr[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_mr");
extern const uint8_t u8g2_font_pxplusibmvga9_mn[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_mn");
extern const uint8_t u8g2_font_pxplusibmvga9_t_all[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_t_all");
extern const uint8_t u8g2_font_pxplusibmvga9_m_all[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga9_m_all");
extern const uint8_t u8g2_font_pxplusibmvga8_tf[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_tf");
extern const uint8_t u8g2_font_pxplusibmvga8_tr[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_tr");
extern const uint8_t u8g2_font_pxplusibmvga8_tn[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_tn");
extern const uint8_t u8g2_font_pxplusibmvga8_mf[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_mf");
extern const uint8_t u8g2_font_pxplusibmvga8_mr[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_mr");
extern const uint8_t u8g2_font_pxplusibmvga8_mn[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_mn");
extern const uint8_t u8g2_font_pxplusibmvga8_t_all[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_t_all");
extern const uint8_t u8g2_font_pxplusibmvga8_m_all[] U8G2_FONT_SECTION("u8g2_font_pxplusibmvga8_m_all");
extern const uint8_t u8g2_font_px437wyse700a_tf[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_tf");
extern const uint8_t u8g2_font_px437wyse700a_tr[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_tr");
extern const uint8_t u8g2_font_px437wyse700a_tn[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_tn");
extern const uint8_t u8g2_font_px437wyse700a_mf[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_mf");
extern const uint8_t u8g2_font_px437wyse700a_mr[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_mr");
extern const uint8_t u8g2_font_px437wyse700a_mn[] U8G2_FONT_SECTION("u8g2_font_px437wyse700a_mn");
extern const uint8_t u8g2_font_px437wyse700b_tf[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_tf");
extern const uint8_t u8g2_font_px437wyse700b_tr[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_tr");
extern const uint8_t u8g2_font_px437wyse700b_tn[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_tn");
extern const uint8_t u8g2_font_px437wyse700b_mf[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_mf");
extern const uint8_t u8g2_font_px437wyse700b_mr[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_mr");
extern const uint8_t u8g2_font_px437wyse700b_mn[] U8G2_FONT_SECTION("u8g2_font_px437wyse700b_mn");

/* end font list */

/*==========================================*/
/* u8g font mapping, might be incomplete.... */


#define u8g_font_10x20   u8g2_font_10x20_tf
#define u8g_font_10x20r   u8g2_font_10x20_tr
#define u8g_font_4x6   u8g2_font_4x6_tf
#define u8g_font_4x6r   u8g2_font_4x6_tr
#define u8g_font_5x7   u8g2_font_5x7_tf
#define u8g_font_5x7r   u8g2_font_5x7_tr
#define u8g_font_5x8   u8g2_font_5x8_tf
#define u8g_font_5x8r   u8g2_font_5x8_tr
#define u8g_font_6x10   u8g2_font_6x10_tf
#define u8g_font_6x10r   u8g2_font_6x10_tr
#define u8g_font_6x12   u8g2_font_6x12_tf
#define u8g_font_6x12r   u8g2_font_6x12_tr
#define u8g_font_6x13B   u8g2_font_6x13B_tf
#define u8g_font_6x13Br   u8g2_font_6x13B_tr
#define u8g_font_6x13   u8g2_font_6x13_tf
#define u8g_font_6x13r   u8g2_font_6x13_tr
#define u8g_font_6x13O   u8g2_font_6x13O_tf
#define u8g_font_6x13Or   u8g2_font_6x13O_tr
#define u8g_font_7x13B   u8g2_font_7x13B_tf
#define u8g_font_7x13Br   u8g2_font_7x13B_tr
#define u8g_font_7x13   u8g2_font_7x13_tf
#define u8g_font_7x13r   u8g2_font_7x13_tr
#define u8g_font_7x13O   u8g2_font_7x13O_tf
#define u8g_font_7x13Or   u8g2_font_7x13O_tr
#define u8g_font_7x14B   u8g2_font_7x14B_tf
#define u8g_font_7x14Br   u8g2_font_7x14B_tr
#define u8g_font_7x14   u8g2_font_7x14_tf
#define u8g_font_7x14r   u8g2_font_7x14_tr
#define u8g_font_8x13B   u8g2_font_8x13B_tf
#define u8g_font_8x13Br   u8g2_font_8x13B_tr
#define u8g_font_8x13   u8g2_font_8x13_tf
#define u8g_font_8x13r   u8g2_font_8x13_tr
#define u8g_font_8x13O   u8g2_font_8x13O_tf
#define u8g_font_8x13Or   u8g2_font_8x13O_tr
#define u8g_font_9x15B   u8g2_font_9x15B_tf
#define u8g_font_9x15Br   u8g2_font_9x15B_tr
#define u8g_font_9x15   u8g2_font_9x15_tf
#define u8g_font_9x15r   u8g2_font_9x15_tr
#define u8g_font_9x18B   u8g2_font_9x18B_tf
#define u8g_font_9x18   u8g2_font_9x18_tf
#define u8g_font_9x18Br   u8g2_font_9x18B_tr
#define u8g_font_9x18r   u8g2_font_9x18_tr
#define u8g_font_cu12   u8g2_font_cu12_tf
#define u8g_font_micro   u8g2_font_micro_tf
#define u8g_font_unifont   u8g2_font_unifont_t_latin
#define u8g_font_unifontr   u8g2_font_unifont_t_latin
#define u8g_font_courB08   u8g2_font_courB08_tf
#define u8g_font_courB08r   u8g2_font_courB08_tr
#define u8g_font_courB10   u8g2_font_courB10_tf
#define u8g_font_courB10r   u8g2_font_courB10_tr
#define u8g_font_courB12   u8g2_font_courB12_tf
#define u8g_font_courB12r   u8g2_font_courB12_tr
#define u8g_font_courB14   u8g2_font_courB14_tf
#define u8g_font_courB14r   u8g2_font_courB14_tr
#define u8g_font_courB18   u8g2_font_courB18_tf
#define u8g_font_courB18r   u8g2_font_courB18_tr
#define u8g_font_courB24   u8g2_font_courB24_tf
#define u8g_font_courB24r   u8g2_font_courB24_tr
#define u8g_font_courB24n   u8g2_font_courB24_tn
#define u8g_font_courR08   u8g2_font_courR08_tf
#define u8g_font_courR08r   u8g2_font_courR08_tr
#define u8g_font_courR10   u8g2_font_courR10_tf
#define u8g_font_courR10r   u8g2_font_courR10_tr
#define u8g_font_courR12   u8g2_font_courR12_tf
#define u8g_font_courR12r   u8g2_font_courR12_tr
#define u8g_font_courR14   u8g2_font_courR14_tf
#define u8g_font_courR14r   u8g2_font_courR14_tr
#define u8g_font_courR18   u8g2_font_courR18_tf
#define u8g_font_courR18r   u8g2_font_courR18_tr
#define u8g_font_courR24   u8g2_font_courR24_tf
#define u8g_font_courR24r   u8g2_font_courR24_tr
#define u8g_font_courR24n   u8g2_font_courR24_tn
#define u8g_font_helvB08   u8g2_font_helvB08_tf
#define u8g_font_helvB08r   u8g2_font_helvB08_tr
#define u8g_font_helvB08n   u8g2_font_helvB08_tn
#define u8g_font_helvB10   u8g2_font_helvB10_tf
#define u8g_font_helvB10r   u8g2_font_helvB10_tr
#define u8g_font_helvB10n   u8g2_font_helvB10_tn
#define u8g_font_helvB12   u8g2_font_helvB12_tf
#define u8g_font_helvB12r   u8g2_font_helvB12_tr
#define u8g_font_helvB12n   u8g2_font_helvB12_tn
#define u8g_font_helvB14   u8g2_font_helvB14_tf
#define u8g_font_helvB14r   u8g2_font_helvB14_tr
#define u8g_font_helvB14n   u8g2_font_helvB14_tn
#define u8g_font_helvB18   u8g2_font_helvB18_tf
#define u8g_font_helvB18r   u8g2_font_helvB18_tr
#define u8g_font_helvB18n   u8g2_font_helvB18_tn
#define u8g_font_helvB24   u8g2_font_helvB24_tf
#define u8g_font_helvB24r   u8g2_font_helvB24_tr
#define u8g_font_helvB24n   u8g2_font_helvB24_tn
#define u8g_font_helvR08   u8g2_font_helvR08_tf
#define u8g_font_helvR08r   u8g2_font_helvR08_tr
#define u8g_font_helvR08n   u8g2_font_helvR08_tn
#define u8g_font_helvR10   u8g2_font_helvR10_tf
#define u8g_font_helvR10r   u8g2_font_helvR10_tr
#define u8g_font_helvR10n   u8g2_font_helvR10_tn
#define u8g_font_helvR12   u8g2_font_helvR12_tf
#define u8g_font_helvR12r   u8g2_font_helvR12_tr
#define u8g_font_helvR12n   u8g2_font_helvR12_tn
#define u8g_font_helvR14   u8g2_font_helvR14_tf
#define u8g_font_helvR14r   u8g2_font_helvR14_tr
#define u8g_font_helvR14n   u8g2_font_helvR14_tn
#define u8g_font_helvR18   u8g2_font_helvR18_tf
#define u8g_font_helvR18r   u8g2_font_helvR18_tr
#define u8g_font_helvR18n   u8g2_font_helvR18_tn
#define u8g_font_helvR24   u8g2_font_helvR24_tf
#define u8g_font_helvR24r   u8g2_font_helvR24_tr
#define u8g_font_helvR24n   u8g2_font_helvR24_tn
#define u8g_font_ncenB08   u8g2_font_ncenB08_tf
#define u8g_font_ncenB08r   u8g2_font_ncenB08_tr
#define u8g_font_ncenB10   u8g2_font_ncenB10_tf
#define u8g_font_ncenB10r   u8g2_font_ncenB10_tr
#define u8g_font_ncenB12   u8g2_font_ncenB12_tf
#define u8g_font_ncenB12r   u8g2_font_ncenB12_tr
#define u8g_font_ncenB14   u8g2_font_ncenB14_tf
#define u8g_font_ncenB14r   u8g2_font_ncenB14_tr
#define u8g_font_ncenB18   u8g2_font_ncenB18_tf
#define u8g_font_ncenB18r   u8g2_font_ncenB18_tr
#define u8g_font_ncenB24   u8g2_font_ncenB24_tf
#define u8g_font_ncenB24r   u8g2_font_ncenB24_tr
#define u8g_font_ncenB24n   u8g2_font_ncenB24_tn
#define u8g_font_ncenR08   u8g2_font_ncenR08_tf
#define u8g_font_ncenR08r   u8g2_font_ncenR08_tr
#define u8g_font_ncenR10   u8g2_font_ncenR10_tf
#define u8g_font_ncenR10r   u8g2_font_ncenR10_tr
#define u8g_font_ncenR12   u8g2_font_ncenR12_tf
#define u8g_font_ncenR12r   u8g2_font_ncenR12_tr
#define u8g_font_ncenR14   u8g2_font_ncenR14_tf
#define u8g_font_ncenR14r   u8g2_font_ncenR14_tr
#define u8g_font_ncenR18   u8g2_font_ncenR18_tf
#define u8g_font_ncenR18r   u8g2_font_ncenR18_tr
#define u8g_font_ncenR24   u8g2_font_ncenR24_tf
#define u8g_font_ncenR24r   u8g2_font_ncenR24_tr
#define u8g_font_ncenR24n   u8g2_font_ncenR24_tn
#define u8g_font_timB08   u8g2_font_timB08_tf
#define u8g_font_timB08r   u8g2_font_timB08_tr
#define u8g_font_timB10   u8g2_font_timB10_tf
#define u8g_font_timB10r   u8g2_font_timB10_tr
#define u8g_font_timB12   u8g2_font_timB12_tf
#define u8g_font_timB12r   u8g2_font_timB12_tr
#define u8g_font_timB14   u8g2_font_timB14_tf
#define u8g_font_timB14r   u8g2_font_timB14_tr
#define u8g_font_timB18   u8g2_font_timB18_tf
#define u8g_font_timB18r   u8g2_font_timB18_tr
#define u8g_font_timB24   u8g2_font_timB24_tf
#define u8g_font_timB24r   u8g2_font_timB24_tr
#define u8g_font_timB24n   u8g2_font_timB24_tn
#define u8g_font_timR08   u8g2_font_timR08_tf
#define u8g_font_timR08r   u8g2_font_timR08_tr
#define u8g_font_timR10   u8g2_font_timR10_tf
#define u8g_font_timR10r   u8g2_font_timR10_tr
#define u8g_font_timR12   u8g2_font_timR12_tf
#define u8g_font_timR12r   u8g2_font_timR12_tr
#define u8g_font_timR14   u8g2_font_timR14_tf
#define u8g_font_timR14r   u8g2_font_timR14_tr
#define u8g_font_timR18   u8g2_font_timR18_tf
#define u8g_font_timR18r   u8g2_font_timR18_tr
#define u8g_font_timR24   u8g2_font_timR24_tf
#define u8g_font_timR24r   u8g2_font_timR24_tr
#define u8g_font_timR24n   u8g2_font_timR24_tn
#define u8g_font_p01type   u8g2_font_p01type_tf
#define u8g_font_p01typer   u8g2_font_p01type_tr
#define u8g_font_lucasfont_alternate   u8g2_font_lucasfont_alternate_tf
#define u8g_font_lucasfont_alternater   u8g2_font_lucasfont_alternate_tr
#define u8g_font_chikita   u8g2_font_chikita_tf
#define u8g_font_chikitar   u8g2_font_chikita_tr
#define u8g_font_pixelle_micro   u8g2_font_pixelle_micro_tf
#define u8g_font_pixelle_micror   u8g2_font_pixelle_micro_tr
#define u8g_font_trixel_square   u8g2_font_trixel_square_tf
#define u8g_font_trixel_squarer   u8g2_font_trixel_square_tr
#define u8g_font_robot_de_niro   u8g2_font_robot_de_niro_tf
#define u8g_font_robot_de_niror   u8g2_font_robot_de_niro_tr
#define u8g_font_baby   u8g2_font_baby_tf
#define u8g_font_babyr   u8g2_font_baby_tr
#define u8g_font_blipfest_07   u8g2_font_blipfest_07_tr
#define u8g_font_blipfest_07r   u8g2_font_blipfest_07_tr
#define u8g_font_blipfest_07n   u8g2_font_blipfest_07_tn
#define u8g_font_profont10   u8g2_font_profont10_tf
#define u8g_font_profont10r   u8g2_font_profont10_tr
#define u8g_font_profont11   u8g2_font_profont11_tf
#define u8g_font_profont11r   u8g2_font_profont11_tr
#define u8g_font_profont12   u8g2_font_profont12_tf
#define u8g_font_profont12r   u8g2_font_profont12_tr
#define u8g_font_profont15   u8g2_font_profont15_tf
#define u8g_font_profont15r   u8g2_font_profont15_tr
#define u8g_font_profont17   u8g2_font_profont17_tf
#define u8g_font_profont17r   u8g2_font_profont17_tr
#define u8g_font_profont22   u8g2_font_profont22_tf
#define u8g_font_profont22r   u8g2_font_profont22_tr
#define u8g_font_profont29   u8g2_font_profont29_tf
#define u8g_font_profont29r   u8g2_font_profont29_tr


/*==========================================*/
/* C++ compatible */

#ifdef __cplusplus
}
#endif


#endif // __u8g2_fonts_H
