#pragma once
struct Stats{
    unsigned int size;
    int range;
    float mean;
    float median;
    int mode;

};

//C2
Stats GetStats(vector<int> array_of_integers){
    Stats statistics;
    int most_repeated_element;
    int repetition_counter = 0;
    unsigned int len = array_of_integers.size();
    statistics.size = len;
    float sum_of_array = 0;
    int max = array_of_integers[0];
    int min = array_of_integers[0];
    for (int i = 0; i < len; i++){
        if (array_of_integers[i] > max){
            max = array_of_integers[i];
        }
        if (array_of_integers[i] < min){
            min = array_of_integers[i];
        }
        sum_of_array += array_of_integers[i];
    }
    int delta = max - min;
    statistics.range = delta;
    float average_value = sum_of_array / len;
    statistics.mean = average_value;


    for (int k = 0 ; k < array_of_integers.size() - 1; k++){
        for (int j = 0; j < array_of_integers.size() - k - 1; j++){
            if (array_of_integers[j] > array_of_integers[j +1]){
                array_of_integers[j] ^= array_of_integers[j +1];
                array_of_integers[j + 1] ^= array_of_integers[j];
                array_of_integers[j] ^= array_of_integers[j +1];
            }

        }
    }
    float median_value;
    if (len % 2 == 0){
        median_value = (array_of_integers[len / 2] + array_of_integers[(len / 2) -1] ) * 0.5;
    }
    else {
        median_value = array_of_integers[len / 2];
    }
    statistics.median = median_value;
    vector<int> most_common_element;
    int mode_value = 0;
    int return_mode;
    for (int i = 0; i < array_of_integers.size(); i++){
        int met_in_array = 0;
        for (int j = 0; j < array_of_integers.size();j++){
            if (array_of_integers[i] == array_of_integers[j]){
                met_in_array++;
            }
        }
        most_common_element.push_back(met_in_array);
        if (mode_value  < most_common_element[i]){
            mode_value = most_common_element[i];
            return_mode = array_of_integers[i];
        }
    }
    statistics.mode = return_mode;



    return statistics;

}