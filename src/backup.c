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

// char* input_main_phase() {
//     /* KAMUS */
//     char* input_user;
//     char* valid_input[9] = {"w","a","s","d","serve","repair","detail","office","prepare"};
//     boolean valid = false;

//     int i = 0;

//     /* ALGORITHM */
//     do {
//         printf("Masukkan Perintah :\n");
//         scanf("%s",&input_user); /* JANGAN LUPA NANTI MASUKINNYA KE ADT MESIN KATA / MESIN KARAKTER */

//         while (!valid && i<9) {
//             if (!strcmp(input_user,valid_input[i])) {   // Note, strcmp kalau sama malah 0
//                 valid = true;
//             } else {
//                 i++;
//             }
//         }
        
//         if (!valid) {
//            printf("Perintah salah, coba lagi\n"); 
//         }
        
//     } while (!valid);

//     return input_user;
// }


// void action_input_main(char* input,boolean status) { // Tambah parameter player sama map buat diupdate, 
// /* Menjalankan perintah input */

// /* KAMUS*/

// /* ALGORITMA */
//     if ((!strcmp("w",input)) || (!strcmp("a",input)) || (!strcmp("s",input)) || (!strcmp("d",input))) {
//         // Update peta
//     } else if (!strcmp("serve",input)) {
//         // Lakukan serve
//     } else if (!strcmp("repair",input)) {
//         // Lakukan repair
//     } else if (!strcmp("detail",input)) {
//         // Lakukan detail
//     } else if (!strcmp("office",input)) {
//         // Lakukan office
//     } else if (!strcmp("prepare",input)) {
//         // Lakukan prepare
//     } else {
//         printf("Something wrong happened\n");
//     }
// }


// W.Length = 1;
    // W.TabKata[0] = 'w';
    // A.Length = 1;
    // A.TabKata[0] = 'a';
    // S.Length = 1;
    // S.TabKata[0] = 's';
    // D.Length = 1;
    // D.TabKata[0] = 'd';

    // Build.Length = 5;
    // Build.TabKata[0] = 'b';
    // Build.TabKata[1] = 'u';
    // Build.TabKata[2] = 'i';
    // Build.TabKata[3] = 'l';
    // Build.TabKata[4] = 'd';

    // Upgrade.Length = 7;
    // Upgrade.TabKata[0] = 'u';
    // Upgrade.TabKata[1] = 'p';
    // Upgrade.TabKata[2] = 'g';
    // Upgrade.TabKata[3] = 'r';
    // Upgrade.TabKata[4] = 'a';
    // Upgrade.TabKata[5] = 'd';
    // Upgrade.TabKata[6] = 'e';

    // Buy.Length = 3;
    // Buy.TabKata[0] = 'b';
    // Buy.TabKata[1] = 'u';
    // Buy.TabKata[2] = 'y';

    // Undo.Length = 4;
    // Undo.TabKata[0] = 'u';
    // Undo.TabKata[1] = 'n';
    // Undo.TabKata[2] = 'd';
    // Undo.TabKata[3] = 'o';

    // Execute.Length = 7;
    // Execute.TabKata[0] = 'e';
    // Execute.TabKata[1] = 'x';
    // Execute.TabKata[2] = 'e';
    // Execute.TabKata[3] = 'c';
    // Execute.TabKata[4] = 'u';
    // Execute.TabKata[5] = 't';
    // Execute.TabKata[6] = 'e';

    // Main.Length = 4;
    // Main.TabKata[0] = 'm';
    // Main.TabKata[1] = 'a';
    // Main.TabKata[2] = 'i';
    // Main.TabKata[3] = 'n';

    // Quit.Length = 4;
    // Quit.TabKata[0] = 'q';
    // Quit.TabKata[1] = 'u';
    // Quit.TabKata[2] = 'i';
    // Quit.TabKata[3] = 't';


// W.Length = 1;
// W.TabKata[0] = 'w';
// A.Length = 1;
// A.TabKata[0] = 'a';
// S.Length = 1;
// S.TabKata[0] = 's';
// D.Length = 1;
// D.TabKata[0] = 'd';

// Serve.Length = 5;
// Serve.TabKata[0] = 's';
// Serve.TabKata[1] = 'e';
// Serve.TabKata[2] = 'r';
// Serve.TabKata[3] = 'v';
// Serve.TabKata[4] = 'e';

// Repair.Length = 6;
// Repair.TabKata[0] = 'r';
// Repair.TabKata[1] = 'e';
// Repair.TabKata[2] = 'p';
// Repair.TabKata[3] = 'a';
// Repair.TabKata[4] = 'i';
// Repair.TabKata[5] = 'r';

// Detail.Length = 6;
// Detail.TabKata[0] = 'd';
// Detail.TabKata[1] = 'e';
// Detail.TabKata[2] = 't';
// Detail.TabKata[3] = 'a';
// Detail.TabKata[4] = 'i';
// Detail.TabKata[5] = 'l';

// Office.Length = 6;
// Office.TabKata[0] = 'o';
// Office.TabKata[1] = 'f';
// Office.TabKata[2] = 'f';
// Office.TabKata[3] = 'i';
// Office.TabKata[4] = 'c';
// Office.TabKata[5] = 'e';

// Prepare.Length = 7;
// Prepare.TabKata[0] = 'p';
// Prepare.TabKata[1] = 'r';
// Prepare.TabKata[2] = 'e';
// Prepare.TabKata[3] = 'p';
// Prepare.TabKata[4] = 'a';
// Prepare.TabKata[5] = 'r';
// Prepare.TabKata[6] = 'e';

// Quit.Length = 4;
// Quit.TabKata[0] = 'm';
// Quit.TabKata[1] = 'a';
// Quit.TabKata[2] = 'i';
// Quit.TabKata[3] = 'n';