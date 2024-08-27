#ifndef FT_CONVERT_BASE_H
#define FT_CONVERT_BASE_H

int find_index(char *base, char digit);
int valid_base(char *base);
long atoi_base(char *str, char *base, int len);
int number_lenght(long number, int base_len);
char *itoa_base(long nbr, char *base, int base_len);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
