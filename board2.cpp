#include "Board.hpp"


Board::Board() {
    tiles = Init_Board();
}

vector<Tile*> Board::Init_Board() {
    cout << "Init_Board" << endl;

     // Vector to store Vertex pointers
        // Dynamically allocate Vertex objects and store their pointers
        for (int i = 0; i < 54; i++) {
            vertices.push_back(new Vertex(i));
        }
    //init 72 edges
        Edge edge0(0, vertices[0], vertices[3]);
        Edge edge1(1, vertices[0], vertices[4]);
        Edge edge2(2, vertices[1], vertices[4]);
        Edge edge3(3, vertices[1], vertices[5]);
        Edge edge4(4, vertices[2], vertices[5]);
        Edge edge5(5, vertices[2], vertices[6]);
        Edge edge6(6, vertices[3], vertices[7]);
        Edge edge7(7, vertices[4], vertices[8]);
        Edge edge8(8, vertices[5], vertices[9]);
        Edge edge9(9, vertices[6], vertices[1]);
        Edge edge10(10, vertices[7], vertices[11]);
        Edge edge11(11, vertices[7], vertices[12]);
        Edge edge12(12, vertices[8], vertices[12]);
        Edge edge13(13, vertices[8], vertices[13]);
        Edge edge14(14, vertices[9], vertices[13]);
        Edge edge15(15, vertices[9], vertices[14]);
        Edge edge16(16, vertices[10], vertices[14]);
        Edge edge17(17, vertices[10], vertices[15]);
        Edge edge18(18, vertices[11], vertices[16]);
        Edge edge19(19, vertices[12], vertices[17]);
        Edge edge20(20, vertices[13], vertices[18]);
        Edge edge21(21, vertices[14], vertices[19]);
        Edge edge22(22, vertices[15], vertices[20]);
        Edge edge23(23, vertices[16], vertices[21]);
        Edge edge24(24, vertices[16], vertices[22]);
        Edge edge25(25, vertices[17], vertices[22]);
        Edge edge26(26, vertices[17], vertices[23]);
        Edge edge27(27, vertices[18], vertices[23]);
        Edge edge28(28, vertices[18], vertices[24]);
        Edge edge29(29, vertices[19], vertices[24]);
        Edge edge30(30, vertices[19], vertices[25]);
        Edge edge31(31, vertices[20], vertices[25]);
        Edge edge32(32, vertices[20], vertices[26]);
        Edge edge33(33, vertices[21], vertices[27]);
        Edge edge34(34, vertices[22], vertices[28]);
        Edge edge35(35, vertices[23], vertices[29]);
        Edge edge36(36, vertices[24], vertices[30]);
        Edge edge37(37, vertices[25], vertices[31]);
        Edge edge38(38, vertices[26], vertices[32]);
        Edge edge39(39, vertices[27], vertices[33]);
        Edge edge40(40, vertices[28], vertices[33]);
        Edge edge41(41, vertices[28], vertices[34]);
        Edge edge42(42, vertices[29], vertices[34]);
        Edge edge43(43, vertices[29], vertices[35]);
        Edge edge44(44, vertices[30], vertices[35]);
        Edge edge45(45, vertices[30], vertices[36]);
        Edge edge46(46, vertices[31], vertices[36]);
        Edge edge47(47, vertices[31], vertices[37]);
        Edge edge48(48, vertices[32], vertices[37]);
        Edge edge49(49, vertices[33], vertices[38]);
        Edge edge50(50, vertices[34], vertices[39]);
        Edge edge51(51, vertices[35], vertices[40]);
        Edge edge52(52, vertices[36], vertices[41]);
        Edge edge53(53, vertices[37], vertices[42]);
        Edge edge54(54, vertices[38], vertices[43]);
        Edge edge55(55, vertices[39], vertices[43]);
        Edge edge56(56, vertices[39], vertices[44]);
        Edge edge57(57, vertices[40], vertices[44]);
        Edge edge58(58, vertices[40], vertices[45]);
        Edge edge59(59, vertices[41], vertices[45]);
        Edge edge60(60, vertices[41], vertices[46]);
        Edge edge61(61, vertices[42], vertices[46]);
        Edge edge62(62, vertices[43], vertices[47]);
        Edge edge63(63, vertices[44], vertices[48]);
        Edge edge64(64, vertices[45], vertices[49]);
        Edge edge65(65, vertices[46], vertices[50]);
        Edge edge66(66, vertices[47], vertices[51]);
        Edge edge67(67, vertices[48], vertices[51]);
        Edge edge68(68, vertices[48], vertices[52]);
        Edge edge69(69, vertices[49], vertices[52]);
        Edge edge70(70, vertices[49], vertices[53]);
        Edge edge71(71, vertices[50], vertices[53]);

    //init 19 tiles
    //each tile has 6 vertex and 6 edges

    //tile 0
    vector<Vertex*> vertex_tile0 = {vertices[0], vertices[3], vertices[4], vertices[7], vertices[8], vertices[12]};
    vector<Edge*> edge_tile0 = {&edge0, &edge1, &edge6, &edge7, &edge11, &edge12};
    Tile tile0(0, vertex_tile0, edge_tile0);
    //tile0.printTile();

    
    //tile 1
    vector<Vertex*> vertex_tile1 = {vertices[1], vertices[4], vertices[5], vertices[8], vertices[9], vertices[13]};
    vector<Edge*> edge_tile1 = {&edge2, &edge3, &edge7, &edge8, &edge13, &edge14};
    Tile tile1(1, vertex_tile1, edge_tile1);

    //tile 2
    vector<Vertex*> vertex_tile2 = {vertices[2], vertices[5], vertices[6], vertices[9], vertices[10], vertices[14]};
    vector<Edge*> edge_tile2 = {&edge4, &edge5, &edge8, &edge9, &edge15, &edge16};
    Tile tile2(2, vertex_tile2, edge_tile2);

    //tile 3
    vector<Vertex*> vertex_tile3 = {vertices[7], vertices[11], vertices[12], vertices[16], vertices[17], vertices[22]};
    vector<Edge*> edge_tile3 = {&edge10, &edge11, &edge18, &edge19, &edge24, &edge25};
    Tile tile3(3, vertex_tile3, edge_tile3);

    //tile 4
    vector<Vertex*> vertex_tile4 = {vertices[8], vertices[12], vertices[13], vertices[17], vertices[18], vertices[23]};
    vector<Edge*> edge_tile4 = {&edge12, &edge13, &edge19, &edge20, &edge26, &edge27};
    Tile tile4(4, vertex_tile4, edge_tile4);

    //tile 5
    vector<Vertex*> vertex_tile5 = {vertices[9], vertices[13], vertices[14], vertices[18], vertices[19], vertices[24]};
    vector<Edge*> edge_tile5 = {&edge14, &edge15, &edge20, &edge21, &edge28, &edge29};
    Tile tile5(5, vertex_tile5, edge_tile5);

    //tile 6
    vector<Vertex*> vertex_tile6 = {vertices[10], vertices[14], vertices[15], vertices[19], vertices[20], vertices[25]};
    vector<Edge*> edge_tile6 = {&edge16, &edge17, &edge21, &edge22, &edge30, &edge31};
    Tile tile6(6, vertex_tile6, edge_tile6);

    //tile 7
    vector<Vertex*> vertex_tile7 = {vertices[16], vertices[21], vertices[22], vertices[27], vertices[28], vertices[33]};
    vector<Edge*> edge_tile7 = {&edge23, &edge24, &edge33, &edge34, &edge39, &edge40};
    Tile tile7(7, vertex_tile7, edge_tile7);

    //tile 8
    vector<Vertex*> vertex_tile8 = {vertices[17], vertices[22], vertices[23], vertices[28], vertices[29], vertices[34]};
    vector<Edge*> edge_tile8 = {&edge25, &edge26, &edge34, &edge35, &edge41, &edge42};
    Tile tile8(8, vertex_tile8, edge_tile8);

    //tile 9
    vector<Vertex*> vertex_tile9 = {vertices[18], vertices[23], vertices[24], vertices[29], vertices[30], vertices[35]};
    vector<Edge*> edge_tile9 = {&edge27, &edge28, &edge35, &edge36, &edge43, &edge44};
    Tile tile9(9, vertex_tile9, edge_tile9);

    //tile 10
    vector<Vertex*> vertex_tile10 = {vertices[19], vertices[24], vertices[25], vertices[30], vertices[31], vertices[36]};
    vector<Edge*> edge_tile10 = {&edge29, &edge30, &edge36, &edge37, &edge45, &edge46};
    Tile tile10(10, vertex_tile10, edge_tile10);
    
    //tile 11
    vector<Vertex*> vertex_tile11 = {vertices[20], vertices[25], vertices[26], vertices[31], vertices[32], vertices[37]};
    vector<Edge*> edge_tile11 = {&edge31, &edge32, &edge37, &edge38, &edge47, &edge48};
    Tile tile11(11, vertex_tile11, edge_tile11);

    //tile 12
    vector<Vertex*> vertex_tile12 = {vertices[28], vertices[33], vertices[34], vertices[38], vertices[39], vertices[43]};
    vector<Edge*> edge_tile12 = {&edge40, &edge41, &edge49, &edge50, &edge54, &edge55};
    Tile tile12(12, vertex_tile12, edge_tile12);

    //tile 13
    vector<Vertex*> vertex_tile13 = {vertices[29], vertices[34], vertices[35], vertices[39], vertices[40], vertices[44]};
    vector<Edge*> edge_tile13 = {&edge42, &edge43, &edge50, &edge51, &edge56, &edge57};
    Tile tile13(13, vertex_tile13, edge_tile13);

    //tile 14
    vector<Vertex*> vertex_tile14 = {vertices[30], vertices[35], vertices[36], vertices[40], vertices[41], vertices[45]};
    vector<Edge*> edge_tile14 = {&edge44, &edge45, &edge51, &edge52, &edge58, &edge59};
    Tile tile14(14, vertex_tile14, edge_tile14);

    //tile 15
    vector<Vertex*> vertex_tile15 = {vertices[31], vertices[36], vertices[37], vertices[41], vertices[42], vertices[46]};
    vector<Edge*> edge_tile15 = {&edge46, &edge47, &edge52, &edge53, &edge60, &edge61};
    Tile tile15(15, vertex_tile15, edge_tile15);

    //tile 16
    vector<Vertex*> vertex_tile16 = {vertices[39], vertices[43], vertices[44], vertices[47], vertices[48], vertices[51]};
    vector<Edge*> edge_tile16 = {&edge55, &edge56, &edge62, &edge63, &edge66, &edge67};
    Tile tile16(16, vertex_tile16, edge_tile16);

    //tile 17
    vector<Vertex*> vertex_tile17 = {vertices[40], vertices[44], vertices[45], vertices[48], vertices[49], vertices[52]};
    vector<Edge*> edge_tile17 = {&edge57, &edge58, &edge63, &edge64, &edge68, &edge69};
    Tile tile17(17, vertex_tile17, edge_tile17);

    //tile 18
    vector<Vertex*> vertex_tile18 = {vertices[41], vertices[45], vertices[46], vertices[49], vertices[50], vertices[53]};
    vector<Edge*> edge_tile18 = {&edge59, &edge60, &edge64, &edge65, &edge70, &edge71};
    Tile tile18(18, vertex_tile18, edge_tile18);

    vector<Tile*> tiles = {&tile0, &tile1, &tile2, &tile3, &tile4, &tile5, &tile6, &tile7, &tile8, &tile9, &tile10, &tile11, &tile12, &tile13, &tile14, &tile15, &tile16, &tile17, &tile18};


    return tiles;


    // //init 54 verteices and put them in a vector
    // Vertex vertex0(0);
    // Vertex vertex1(1);
    // Vertex vertex2(2);
    // Vertex vertex3(3);
    // Vertex vertex4(4);
    // Vertex vertex5(5);
    // Vertex vertex6(6);
    // Vertex vertex7(7);
    // Vertex vertex8(8);
    // Vertex vertex9(9);
    // Vertex vertex10(10);
    // Vertex vertex11(11);
    // Vertex vertex12(12);
    // Vertex vertex13(13);
    // Vertex vertex14(14);
    // Vertex vertex15(15);
    // Vertex vertex16(16);
    // Vertex vertex17(17);
    // Vertex vertex18(18);
    // Vertex vertex19(19);
    // Vertex vertex20(20);
    // Vertex vertex21(21);
    // Vertex vertex22(22);
    // Vertex vertex23(23);
    // Vertex vertex24(24);
    // Vertex vertex25(25);
    // Vertex vertex26(26);
    // Vertex vertex27(27);
    // Vertex vertex28(28);
    // Vertex vertex29(29);
    // Vertex vertex30(30);
    // Vertex vertex31(31);
    // Vertex vertex32(32);
    // Vertex vertex33(33);
    // Vertex vertex34(34);
    // Vertex vertex35(35);
    // Vertex vertex36(36);
    // Vertex vertex37(37);
    // Vertex vertex38(38);
    // Vertex vertex39(39);
    // Vertex vertex40(40);
    // Vertex vertex41(41);
    // Vertex vertex42(42);
    // Vertex vertex43(43);
    // Vertex vertex44(44);
    // Vertex vertex45(45);
    // Vertex vertex46(46);
    // Vertex vertex47(47);
    // Vertex vertex48(48);
    // Vertex vertex49(49);
    // Vertex vertex50(50);
    // Vertex vertex51(51);
    // Vertex vertex52(52);
    // Vertex vertex53(53);



    // // //init 72 edges
    // Edge edge0(0, &vertex0, &vertex3);
    // Edge edge1(1, &vertex0, &vertex4);
    // Edge edge2(2, &vertex1, &vertex4);
    // Edge edge3(3, &vertex1, &vertex5);
    // Edge edge4(4, &vertex2, &vertex5);
    // Edge edge5(5, &vertex2, &vertex6);
    // Edge edge6(6, &vertex3, &vertex7);
    // Edge edge7(7, &vertex4, &vertex8);
    // Edge edge8(8, &vertex5, &vertex9);
    // Edge edge9(9, &vertex6, &vertex1);
    // Edge edge10(10, &vertex7, &vertex11);
    // Edge edge11(11, &vertex7, &vertex12);
    // Edge edge12(12, &vertex8, &vertex12);
    // Edge edge13(13, &vertex8, &vertex13);
    // Edge edge14(14, &vertex9, &vertex13);
    // Edge edge15(15, &vertex9, &vertex14);
    // Edge edge16(16, &vertex10, &vertex14);
    // Edge edge17(17, &vertex10, &vertex15);
    // Edge edge18(18, &vertex11, &vertex16);
    // Edge edge19(19, &vertex12, &vertex17);
    // Edge edge20(20, &vertex13, &vertex18);
    // Edge edge21(21, &vertex14, &vertex19);
    // Edge edge22(22, &vertex15, &vertex20);
    // Edge edge23(23, &vertex16, &vertex21);
    // Edge edge24(24, &vertex16, &vertex22);
    // Edge edge25(25, &vertex17, &vertex22);
    // Edge edge26(26, &vertex17, &vertex23);
    // Edge edge27(27, &vertex18, &vertex23);
    // Edge edge28(28, &vertex18, &vertex24);
    // Edge edge29(29, &vertex19, &vertex24);
    // Edge edge30(30, &vertex19, &vertex25);
    // Edge edge31(31, &vertex20, &vertex25);
    // Edge edge32(32, &vertex20, &vertex26);
    // Edge edge33(33, &vertex21, &vertex27);
    // Edge edge34(34, &vertex22, &vertex28);
    // Edge edge35(35, &vertex23, &vertex29);
    // Edge edge36(36, &vertex24, &vertex30);
    // Edge edge37(37, &vertex25, &vertex31);
    // Edge edge38(38, &vertex26, &vertex32);
    // Edge edge39(39, &vertex27, &vertex33);
    // Edge edge40(40, &vertex28, &vertex33);
    // Edge edge41(41, &vertex28, &vertex34);
    // Edge edge42(42, &vertex29, &vertex34);
    // Edge edge43(43, &vertex29, &vertex35);
    // Edge edge44(44, &vertex30, &vertex35);
    // Edge edge45(45, &vertex30, &vertex36);
    // Edge edge46(46, &vertex31, &vertex36);
    // Edge edge47(47, &vertex31, &vertex37);
    // Edge edge48(48, &vertex32, &vertex37);
    // Edge edge49(49, &vertex33, &vertex38);
    // Edge edge50(50, &vertex34, &vertex39);
    // Edge edge51(51, &vertex35, &vertex40);
    // Edge edge52(52, &vertex36, &vertex41);
    // Edge edge53(53, &vertex37, &vertex42);
    // Edge edge54(54, &vertex38, &vertex43);
    // Edge edge55(55, &vertex39, &vertex43);
    // Edge edge56(56, &vertex39, &vertex44);
    // Edge edge57(57, &vertex40, &vertex44);
    // Edge edge58(58, &vertex40, &vertex45);
    // Edge edge59(59, &vertex41, &vertex45);
    // Edge edge60(60, &vertex41, &vertex46);
    // Edge edge61(61, &vertex42, &vertex46);
    // Edge edge62(62, &vertex43, &vertex47);
    // Edge edge63(63, &vertex44, &vertex48);
    // Edge edge64(64, &vertex45, &vertex49);
    // Edge edge65(65, &vertex46, &vertex50);
    // Edge edge66(66, &vertex47, &vertex51);
    // Edge edge67(67, &vertex48, &vertex51);
    // Edge edge68(68, &vertex48, &vertex52);
    // Edge edge69(69, &vertex49, &vertex52);
    // Edge edge70(70, &vertex49, &vertex53);
    // Edge edge71(71, &vertex50, &vertex53);


    //  /*
    // init 19 tiles
    // each tile has 6 vertex and 6 edges
    // */

    // //tile 0
    // vector<Vertex*> vertex_tile0 = {&vertex0, &vertex3, &vertex4, &vertex7, &vertex8, &vertex12};
    // vector<Edge*> edge_tile0 = {&edge0, &edge1, &edge6, &edge7, &edge11, &edge12};
    // Tile tile0(0, vertex_tile0, edge_tile0);
    // tile0.printTile();

    // //tile 1
    // vector<Vertex*> vertex_tile1 = {&vertex1, &vertex4, &vertex5, &vertex8, &vertex9, &vertex13};
    // vector<Edge*> edge_tile1 = {&edge2, &edge3, &edge7, &edge8, &edge13, &edge14};
    // Tile tile1(1, vertex_tile1, edge_tile1);

    // //tile 2
    // vector<Vertex*> vertex_tile2 = {&vertex2, &vertex5, &vertex6, &vertex9, &vertex10, &vertex14};
    // vector<Edge*> edge_tile2 = {&edge4, &edge5, &edge8, &edge9, &edge15, &edge16};
    // Tile tile2(2, vertex_tile2, edge_tile2);

    // //tile 3
    // vector<Vertex*> vertex_tile3 = {&vertex7, &vertex11, &vertex12, &vertex16, &vertex17, &vertex22};
    // vector<Edge*> edge_tile3 = {&edge10, &edge11, &edge18, &edge19, &edge24, &edge25};
    // Tile tile3(3, vertex_tile3, edge_tile3);

    // //tile 4
    // vector<Vertex*> vertex_tile4 = {&vertex8, &vertex12, &vertex13, &vertex17, &vertex18, &vertex23};
    // vector<Edge*> edge_tile4 = {&edge12, &edge13, &edge19, &edge20, &edge26, &edge27};
    // Tile tile4(4, vertex_tile4, edge_tile4);

    // //tile 5
    // vector<Vertex*> vertex_tile5 = {&vertex9, &vertex13, &vertex14, &vertex18, &vertex19, &vertex24};
    // vector<Edge*> edge_tile5 = {&edge14, &edge15, &edge20, &edge21, &edge28, &edge29};
    // Tile tile5(5, vertex_tile5, edge_tile5);

    // //tile 6
    // vector<Vertex*> vertex_tile6 = {&vertex10, &vertex14, &vertex15, &vertex19, &vertex20, &vertex25};
    // vector<Edge*> edge_tile6 = {&edge16, &edge17, &edge21, &edge22, &edge30, &edge31};
    // Tile tile6(6, vertex_tile6, edge_tile6);

    // //tile 7
    // vector<Vertex*> vertex_tile7 = {&vertex16, &vertex21, &vertex22, &vertex27, &vertex28, &vertex33};
    // vector<Edge*> edge_tile7 = {&edge23, &edge24, &edge33, &edge34, &edge39, &edge40};
    // Tile tile7(7, vertex_tile7, edge_tile7);

    // //tile 8
    // vector<Vertex*> vertex_tile8 = {&vertex17, &vertex22, &vertex23, &vertex28, &vertex29, &vertex34};
    // vector<Edge*> edge_tile8 = {&edge25, &edge26, &edge34, &edge35, &edge41, &edge42};
    // Tile tile8(8, vertex_tile8, edge_tile8);

    // //tile 9
    // vector<Vertex*> vertex_tile9 = {&vertex18, &vertex23, &vertex24, &vertex29, &vertex30, &vertex35};
    // vector<Edge*> edge_tile9 = {&edge27, &edge28, &edge35, &edge36, &edge43, &edge44};
    // Tile tile9(9, vertex_tile9, edge_tile9);

    // //tile 10
    // vector<Vertex*> vertex_tile10 = {&vertex19, &vertex24, &vertex25, &vertex30, &vertex31, &vertex36};
    // vector<Edge*> edge_tile10 = {&edge29, &edge30, &edge36, &edge37, &edge45, &edge46};
    // Tile tile10(10, vertex_tile10, edge_tile10);

    // //tile 11
    // vector<Vertex*> vertex_tile11 = {&vertex20, &vertex25, &vertex26, &vertex31, &vertex32, &vertex37};
    // vector<Edge*> edge_tile11 = {&edge31, &edge32, &edge37, &edge38, &edge47, &edge48};
    // Tile tile11(11, vertex_tile11, edge_tile11);

    // //tile 12
    // vector<Vertex*> vertex_tile12 = {&vertex28, &vertex33, &vertex34, &vertex38, &vertex39, &vertex43};
    // vector<Edge*> edge_tile12 = {&edge40, &edge41, &edge49, &edge50, &edge54, &edge55};
    // Tile tile12(12, vertex_tile12, edge_tile12);

    // //tile 13
    // vector<Vertex*> vertex_tile13 = {&vertex29, &vertex34, &vertex35, &vertex39, &vertex40, &vertex44};
    // vector<Edge*> edge_tile13 = {&edge42, &edge43, &edge50, &edge51, &edge56, &edge57};
    // Tile tile13(13, vertex_tile13, edge_tile13);

    // //tile 14
    // vector<Vertex*> vertex_tile14 = {&vertex30, &vertex35, &vertex36, &vertex40, &vertex41, &vertex45};
    // vector<Edge*> edge_tile14 = {&edge44, &edge45, &edge51, &edge52, &edge58, &edge59};
    // Tile tile14(14, vertex_tile14, edge_tile14);

    // //tile 15
    // vector<Vertex*> vertex_tile15 = {&vertex31, &vertex36, &vertex37, &vertex41, &vertex42, &vertex46};
    // vector<Edge*> edge_tile15 = {&edge46, &edge47, &edge52, &edge53, &edge60, &edge61};
    // Tile tile15(15, vertex_tile15, edge_tile15);

    // //tile 16
    // vector<Vertex*> vertex_tile16 = {&vertex39, &vertex43, &vertex44, &vertex47, &vertex48, &vertex51};
    // vector<Edge*> edge_tile16 = {&edge55, &edge56, &edge62, &edge63, &edge66, &edge67};
    // Tile tile16(16, vertex_tile16, edge_tile16);

    // //tile 17
    // vector<Vertex*> vertex_tile17 = {&vertex40, &vertex44, &vertex45, &vertex48, &vertex49, &vertex52};
    // vector<Edge*> edge_tile17 = {&edge57, &edge58, &edge63, &edge64, &edge68, &edge69};
    // Tile tile17(17, vertex_tile17, edge_tile17);

    // //tile 18
    // vector<Vertex*> vertex_tile18 = {&vertex41, &vertex45, &vertex46, &vertex49, &vertex50, &vertex53};
    // vector<Edge*> edge_tile18 = {&edge59, &edge60, &edge64, &edge65, &edge70, &edge71};
    // Tile tile18(18, vertex_tile18, edge_tile18);

    // vector<Tile *> tiles = {&tile0, &tile1, &tile2, &tile3, &tile4, &tile5, &tile6, &tile7, &tile8, &tile9, &tile10, &tile11, &tile12, &tile13, &tile14, &tile15, &tile16, &tile17, &tile18};
    // return tiles;

}

void Board:: InitResourcesAndNumbers(){
    //array of resources
    int resources[18] = {WOOD, WOOD, WOOD, WOOD, BRICK, BRICK, BRICK, SHEEP, SHEEP, SHEEP, SHEEP, WHEAT, WHEAT, WHEAT, WHEAT, IRON, IRON,IRON};
    //set desert tile in the middle
    tiles[9]->setResource(DESERT);
    tiles[9]->setNumber(0);
    //array of numbers
    int numbers[18] = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    //shuffle the resources
    //set random resource and number for each tile, 
    //each resource and number will be used only once
    for (int i = 0; i < 9; i++) {
        int random1 = rand() % 18;
        while (resources[random1] == -1) {
            random1 = rand() % 18;
        }
        tiles[i] -> setResource(resources[random1]);
        int random2 = rand() % 18;
        while (numbers[random2] == -1) {
            random2 = rand() % 18;
        }
        tiles[i] ->setNumber(numbers[random2]);
        resources[random1] = -1;
        numbers[random2] = -1;
    }
    for (int i = 10; i < 19; i++) {
          int random1 = rand() % 18;
        while (resources[random1] == -1) {
            random1 = rand() % 18;
        }
        tiles[i] -> setResource(resources[random1]);
        int random2 = rand() % 18;
        while (numbers[random2] == -1) {
            random2 = rand() % 18;
        }
        tiles[i] ->setNumber(numbers[random2]);
        resources[random1] = -1;
        numbers[random2] = -1;
    }

        //check that all resources and numbers are used
        // for (int i =0 ; i < 18; i++){
        //     cout << "numbers " << numbers[i]
        //     << ", resource: " << resources[i] << " number: "<< endl;
        // }

}

void Board::printBoard()
{
    for (size_t i = 0; i < 19 ; i++)
    {
        tiles[i]->printTile();
    }
}
