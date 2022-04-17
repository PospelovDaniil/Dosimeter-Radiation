#define CLASS_PROPERTY(type, var)                                \
  private:                                                       \
    type m_##var;                                                \
  public:                                                        \
    type get_##var()            const noexcept { return m_##var;}\
    void set_##var(const type &value) noexcept { m_##var = value;}

#define zero(p_var)\
  memset(p_var, 0, sizeof(*p_var));

#ifdef ESP8266
  #define GPIO_IN ((volatile uint32_t*) 0x60000318)
#endif  // 0x6000 PIN 318 

#ifdef ESP8266
  #define FAST_WH(pin)\
      GPOS = (1 << pin)

  #define FAST_WL(pin)\
      GPOC = (1 << pin)

/* examples for fast read
#define CLOCK 0x0010 // GPIO4 bit mask
#define DATA 0x0020 // GPIO5 bit mask
*/
#define FAST_READ(pin_mask)\
      (*GPIO_IN & pin_mask)
#endif

#ifdef ESP32
  #define FAST_WH(pin)\
    GPIO.out_w1ts = ((uint32_t)1 << pin)

  #define FAST_WL(pin)\
    GPIO.out_w1tc = ((uint32_t)1 << pin)
  
  #define FAST_PR(pin)\
   // need code
#endif