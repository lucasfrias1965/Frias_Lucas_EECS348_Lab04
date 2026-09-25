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
                return (value_given * 0.6) - 32;
            case Kelvin:
                return (value_given) - 273.15;
            case Celcius:
                return (value_given);
        }
        return 0;
}

float convert_c_to_f(float value_given){
        return (1.8 * value_given) + 32;
}
float convert_c_to_k(float value_given){
        return value_given + 273.15;
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
    switch (temp_out){
        case Farenheit:
            result = convert_c_to_f(user_input_in_celcius);
            break;
        case Kelvin:
            result =  convert_c_to_k(user_input_in_celcius);
        case Celcius:
            result = user_input_in_celcius;
    }
    
    printf("Converted Temperature: %.3f\n", result);
    printf("Temperature Category: ");
    if (user_input_in_celcius < 0) printf("Cold\nWeather Advisory: Wear a Jacket");
    else if (user_input_in_celcius < 10) printf("Cold\nWeather Advisory: Decent weather, maybe wear a thingy");
    else if (user_input_in_celcius < 25) printf("Comfortable\nWeather Advisory: Great weather");
    else if (user_input_in_celcius < 35) printf("Hot\nWeather Advisory: Maybe wear super light clothing");
    else printf("Extreme Heat\nWeather Advisory: it's the end of days :(");
    printf("\n");
    return 0;
}
