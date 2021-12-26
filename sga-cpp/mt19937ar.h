/********************************
  Author: Tian-Li Yu
  E-mail: tianliyu@nextumi.com
********************************/

#ifndef MT19937AR_H_
#define MT19937AR_H_

#ifdef __cplusplus
extern "C" {
#endif

void init_by_array (unsigned long init_key[], int key_length);
                                 //[0,1]
double genrand_real1 (void);
                                 //[0,1)
double genrand_real2 (void);
                                 //(0,1)
double genrand_real3 (void);
                                 //[0,1)
double genrand_res53 (void);

#ifdef __cplusplus
}
#endif

#endif
