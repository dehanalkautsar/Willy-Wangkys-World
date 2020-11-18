// /* KAMUS */
// char input_user[10];
// char* valid_input[10] = {"w","a","s","d","build","upgrade","buy","undo","execute","main"};
// boolean valid = false;

// /* ALGORITMA */
// do {
//     // To be edited pake mesin kata
//     printf("Masukkan perintah :\n");
//     scanf("%s",input_user); 

//     int i = 0;
//     while (!valid && i<10) {
//         if (!strcmp(input_user,valid_input[i])) {   // Note, strcmp kalau sama malah return 0
//             valid = true;
//         } else {
//             i++;
//         } 
//     }
//     if (!valid) {
//        printf("Perintah salah, coba lagi\n"); 
//     }

// } while (!valid);


// void action_prepration_phase(char* input,boolean status) { // Tambah parameter player sama map buat diupdate, 
// /* Menjalankan perintah input */

// /* KAMUS*/

// /* ALGORITMA */
//     if ((!strcmp("w",input)) || (!strcmp("a",input)) || (!strcmp("s",input)) || (!strcmp("d",input))) {
//         // Update peta
//     } else if (!strcmp("build",input)) {
//         // Lakukan build
//     } else if (!strcmp("upgrade",input)) {
//         // Lakukan upgrade
//     } else if (!strcmp("buy",input)) {
//         // Lakukan buy
//     } else if (!strcmp("undo",input)) {
//         // Lakukan undo
//     } else if (!strcmp("execute",input)) {
//         // Lakukan execute
//     } else if (!strcmp("main",input)) {
//         // Lakukan main
//     } else {
//         printf("Something wrong happened\n");
//     }
// }