#include <stdio.h>
#include <stdint.h>
typedef enum {
    Celcius,
    Farenheit,
    Kelvin,
    Unknown,
} temp;

static inline temp get_temp(char a){
    switch (a){
        case 'F':
            return Farenheit;
        case 'K':
            return Kelvin;
        case 'C':
            return Celcius;
        default:
            return Unknown;
    }

}


float convert_to_cel(float value_given, temp temp_given){
        switch (temp_given){
            case Farenheit:
                return (value_given - 32)* 9/5;
            case Kelvin:
                return (value_given) + 273.15;
            case Celcius:
                return (value_given);
        }
        return 0;
}

float convert_c_to_f(float value_given){
        return 1.8 * value_given + 32;
}
float convert_c_to_k(float value_given){
        return value_given - 273.15;
}

int main(){
    float tempin;
    char scale_init;
    char scale_final; 
    uint8_t ret;

    temp_input:
        printf("Enter the temperature value: ");
        ret = scanf(" %f", &tempin);
        if (ret != 1){
            while (getchar() != '\n')
            goto temp_input;
        }

    scale_init_input:
        printf("Enter the original scale (C,F, or K): ");
        ret = scanf(" %c", &scale_init);
        if (ret != 1){
            while (getchar() != '\n')
            goto temp_input;
        }

    scale_final_input:
        printf("Enter the scale to convert to (C, F, or K: ");
        ret = scanf(" %c", &scale_final);
        if (ret != 1){
            while (getchar() != '\n')
            goto temp_input;
        }

    temp temp_in = get_temp(scale_init);
    temp temp_out = get_temp(scale_final);
    float user_input_in_celcius = convert_to_cel(tempin, temp_in);
    float result;
    printf("Converted Temperature: ");
    switch (temp_out){
        case Celcius:
            printf("%f", result);
            break;
        case Farenheit:
            printf("%f", convert_c_to_f(temp_in)); 
            break;
        case Kelvin:
            printf("%f", convert_c_to_k(temp_in)); 
    }
    printf("\n");
    
    

    return 0;
}
