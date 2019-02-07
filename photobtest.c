//
//  Ben Gertz
//  Photobomb
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

int** add_file_to_master(char* fname, int current_file_number, int fsize);
int* size_of_photo(char* fname, int* size_of_p_val);
int mode(int lst[], int num_ele);

typedef struct photo_struct{
    int pixel[3];
    
} photo;
// Scan in N amount of photos. For evey triplet we create a new array and add it to the array

int size_of_open_folder(int folder_size, char* fname, int size_of_p_val, int* colums_rows){
    //printf("please enter the full file path of the folder you want to get photos from\n");
    //scanf("%s", fname);
    int* intermediate;
    char file_path[100] = "/Users/benjamingertz/Desktop/nospaces/photobomb2/photos/";
    DIR* folder;
    struct dirent *files;
    folder = opendir(fname);
    
    if (folder == NULL) {
        printf("could not open folder photos\n");
        return -1;
    }
    
    while((files = readdir(folder)) != NULL){
        if ((files->d_name[0] != '.')){
            
            folder_size++;
            
        }
    }
    rewinddir(folder);
    while((files = readdir(folder)) != NULL){
        if ((files->d_name[0] != '.')){
            
            strcat(file_path, files ->d_name);
            intermediate = size_of_photo(file_path, &size_of_p_val);
            break;
            
        }
    }
    colums_rows[0] = intermediate[0];
    colums_rows[1] = intermediate[1];
    
    closedir(folder);
    return folder_size;
}
int*** open_folder(char* fname, int fsize, int* size_of_p_val){
    
    char file_path[100] = "/Users/benjamingertz/Desktop/nospaces/photobomb2/photos/";
    struct dirent *files;
    
    DIR* folder;
    folder = opendir(fname);
    int current_file_number = 0;
    int*** m = (int***)malloc(fsize * sizeof(sizeof(size_of_p_val)));
    while((files = readdir(folder))!= NULL){
        if ((files->d_name[0] != '.')){
            
            strcat(file_path, files ->d_name);
            m[current_file_number] = add_file_to_master(file_path, current_file_number, fsize);
            ++current_file_number;
            strcpy(file_path, "/Users/benjamingertz/Desktop/nospaces/photobomb2/photos/");
        }
    }
    closedir(folder);
    
    
    
    return m;
}
int* size_of_photo(char* fname, int* size_of_p_val){
    char encoding[2];
    static int c_r[2];
    
    FILE* inFile = NULL;
    int columns;
    int rows;
    int max_color_val;
    int** arr_photo;
    inFile = fopen(fname, "r");
    
    fscanf(inFile, "%s %d %d %d", encoding, &columns, &rows, &max_color_val);
    arr_photo = (int**)malloc(sizeof(int*) * rows * columns);
    
    arr_photo[0] = (int*) malloc(3 * sizeof(arr_photo[0]));
    c_r[0] = columns;
    c_r[1] = rows;
    
    fclose(inFile);
    return c_r;
}

int** add_file_to_master(char* fname, int current_file_number, int fsize){
    char encoding[2];
    FILE* inFile = NULL;
    
    int columns;
    int rows;
    int max_color_val;
    int** arr_photo;
    inFile = fopen(fname, "r");
    
    fscanf(inFile, "%s %d %d %d", encoding, &columns, &rows, &max_color_val);
    
    
    
    arr_photo = (int**)malloc(sizeof(int*) * rows * columns * 3);
    for(int i = 0; i < (rows * columns); ++i){
        arr_photo[i] = (int*) malloc(3 * sizeof(int));
    }
    
    
    
    
    for(int i=0; i < (columns * rows); i++){
        
        fscanf(inFile, "%d %d %d", &arr_photo[i][0], &arr_photo[i][1], &arr_photo[i][2]);
        
    }
    
    fclose(inFile);
    return arr_photo;
}
int** math_it(int*** master_lst, int num_pxls, int folder_size){
    /*
     for each triplet i'm comparing each triplet value to find out which one is used the most then i take the most common RGBs and adding it to a new
     list
     */
    
    int red[folder_size];
    int green[folder_size];
    int blue[folder_size];
    int** fin_photo = (int**)malloc(sizeof(int*) *num_pxls* 3);
    
    for(int i = 0; i < num_pxls; i++){
        fin_photo[i] = (int*) malloc(3 * sizeof(int));
    }
    
    for(int triplet = 0; triplet < num_pxls; triplet++){
        for(int photo = 0; photo < folder_size; photo++){
            red[photo] = master_lst[photo][triplet][0];
            green[photo] = master_lst[photo][triplet][1];
            blue[photo] = master_lst[photo][triplet][2];
        }
        fin_photo[triplet][0] = mode(red, folder_size);
        fin_photo[triplet][1] = mode(green, folder_size);
        fin_photo[triplet][2] = mode(blue, folder_size);
    }
    
    return fin_photo;
    //master_lst[photo][triplet][RGB]
    
}


int mode(int lst[], int num_ele) {
    int maxValue = 0;
    int maxCount = 0;
    
    for (int i = 0; i < num_ele; ++i) {
        int count = 0;
        
        for (int j = 0; j < num_ele; ++j) {
            if (lst[j] == lst[i])
                ++count;
        }
        
        if (count > maxCount) {
            maxCount = count;
            maxValue = lst[i];
        }
    }
    
    return maxValue;
}

int main() {
    int folder_size = 0;
    char fname[100];
    int size_of_p_val = 0;
    int num_pxls;
    int colums_rows[2];
    
    printf("please enter the full file path of the folder you want to get photos from\n");
    scanf("%s", fname);
    //FIXME: you need to define the size of master after open_folder has been called so that folder_size is updated
    
    
    folder_size = size_of_open_folder(folder_size, fname, size_of_p_val, colums_rows);
    printf("this is folder size in main after the size of open folder call: %d\n", folder_size);
    printf("This is r_c_size in main: %d %d\n", colums_rows[0], colums_rows[1]);
    int*** master;
    num_pxls = colums_rows[0] * colums_rows[1];
    master = open_folder(fname, folder_size, &size_of_p_val);
    printf("Num pixels in main: %d\n", num_pxls);
    printf("folder size: %d\n", folder_size);
    
    int** out_photo = (int**)malloc(sizeof(int*) *num_pxls* 3);
    
    out_photo = math_it(master, num_pxls, folder_size);
    printf("this is the final photo values: \n");
    
    //DIR* out_run;
    //out_run = opendir(fname);
    char out_path[10] = "output.ppm";
    strcat(fname, out_path);
    FILE *output = fopen(fname, "w");
    fprintf(output, "P3 %d %d 255 ", colums_rows[0], colums_rows[1]);
    for(int i = 0; i < num_pxls; i++){
        fprintf(output, "%d %d %d ", out_photo[i][0], out_photo[i][1], out_photo[i][2]);
    }
    fclose(output);
    printf("Fixed photo was placed in the given directory. It is called output.ppm");
    
//
//    for(int i = 0; i < folder_size; i++){
//        for(int j = 0; j < num_pxls; j++){
//            printf("This is one output from master file number %d : %d %d %d\n", i, master[i][j][0], master[i][j][1], master[i][j][2]);
//        }
//    }
//
    
    
    
    /*
     inFile = fopen("/Users/benjamingertz/Desktop/Computer Science/photobomb/photos/smallgreen.ppm", "r");
     if (inFile == NULL) {
     printf("Could not open file smallgreen.ppm\n");
     return -1; // -1 indicates error
     }
     folder = opendir("/Users/benjamingertz/Desktop/Computer Science/photobomb/photos");
     if (folder == NULL) {
     printf("could not open folder photos\n");
     return -1;
     }
     
     char encoding[2];
     int columns;
     int rows;
     int max_color_val;
     int** arr_photo;
     
     fscanf(inFile, "%s %d %d %d", encoding, &columns, &rows, &max_color_val);
     
     
     arr_photo = (int**)malloc(sizeof(int*) * rows * columns);
     for(int i = 0; i < (rows * columns); ++i){
     arr_photo[i] = (int*) malloc(3 * sizeof(arr_photo[i]));
     }
     
     while((files = readdir(folder)) != NULL){
     
     }
     for(int i=0; i < (columns * rows); i++){
     fscanf(inFile, "%d %d %d", &arr_photo[i][0], &arr_photo[i][1], &arr_photo[i][2]);
     }
     
     
     printf("%s\n%d\n%d\n%d\n", encoding, columns, rows, max_color_val);
     
     
     for(int j = 0; j < (columns * rows); ++j){
     printf("%d %d %d\n", arr_photo[j][0], arr_photo[j][1], arr_photo[j][2]);
     }
     */
}
