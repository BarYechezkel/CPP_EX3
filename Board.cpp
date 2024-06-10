#include "Board.hpp"

Board::Board()
{
    Init_Board();
}

void Board::Init_Board()
{
    cout << "Init_Board" << endl;

    // init 54 verteices and put them in a vector
    vertices.resize(54);
    for (int i = 0; i < 54; i++)
    {
        vertices[i] = Vertex(i);
    }

    // //init 72 edges
    Edge edge0(0, &vertices[0], &vertices[3]);
    Edge edge1(1, &vertices[0], &vertices[4]);
    Edge edge2(2, &vertices[1], &vertices[4]);
    Edge edge3(3, &vertices[1], &vertices[5]);
    Edge edge4(4, &vertices[2], &vertices[5]);
    Edge edge5(5, &vertices[2], &vertices[6]);
    Edge edge6(6, &vertices[3], &vertices[7]);
    Edge edge7(7, &vertices[4], &vertices[8]);
    Edge edge8(8, &vertices[5], &vertices[9]);
    Edge edge9(9, &vertices[6], &vertices[1]);
    Edge edge10(10, &vertices[7], &vertices[11]);
    Edge edge11(11, &vertices[7], &vertices[12]);
    Edge edge12(12, &vertices[8], &vertices[12]);
    Edge edge13(13, &vertices[8], &vertices[13]);
    Edge edge14(14, &vertices[9], &vertices[13]);
    Edge edge15(15, &vertices[9], &vertices[14]);
    Edge edge16(16, &vertices[10], &vertices[14]);
    Edge edge17(17, &vertices[10], &vertices[15]);
    Edge edge18(18, &vertices[11], &vertices[16]);
    Edge edge19(19, &vertices[12], &vertices[17]);
    Edge edge20(20, &vertices[13], &vertices[18]);
    Edge edge21(21, &vertices[14], &vertices[19]);
    Edge edge22(22, &vertices[15], &vertices[20]);
    Edge edge23(23, &vertices[16], &vertices[21]);
    Edge edge24(24, &vertices[16], &vertices[22]);
    Edge edge25(25, &vertices[17], &vertices[22]);
    Edge edge26(26, &vertices[17], &vertices[23]);
    Edge edge27(27, &vertices[18], &vertices[23]);
    Edge edge28(28, &vertices[18], &vertices[24]);
    Edge edge29(29, &vertices[19], &vertices[24]);
    Edge edge30(30, &vertices[19], &vertices[25]);
    Edge edge31(31, &vertices[20], &vertices[25]);
    Edge edge32(32, &vertices[20], &vertices[26]);
    Edge edge33(33, &vertices[21], &vertices[27]);
    Edge edge34(34, &vertices[22], &vertices[28]);
    Edge edge35(35, &vertices[23], &vertices[29]);
    Edge edge36(36, &vertices[24], &vertices[30]);
    Edge edge37(37, &vertices[25], &vertices[31]);
    Edge edge38(38, &vertices[26], &vertices[32]);
    Edge edge39(39, &vertices[27], &vertices[33]);
    Edge edge40(40, &vertices[28], &vertices[33]);
    Edge edge41(41, &vertices[28], &vertices[34]);
    Edge edge42(42, &vertices[29], &vertices[34]);
    Edge edge43(43, &vertices[29], &vertices[35]);
    Edge edge44(44, &vertices[30], &vertices[35]);
    Edge edge45(45, &vertices[30], &vertices[36]);
    Edge edge46(46, &vertices[31], &vertices[36]);
    Edge edge47(47, &vertices[31], &vertices[37]);
    Edge edge48(48, &vertices[32], &vertices[37]);
    Edge edge49(49, &vertices[33], &vertices[38]);
    Edge edge50(50, &vertices[34], &vertices[39]);
    Edge edge51(51, &vertices[35], &vertices[40]);
    Edge edge52(52, &vertices[36], &vertices[41]);
    Edge edge53(53, &vertices[37], &vertices[42]);
    Edge edge54(54, &vertices[38], &vertices[43]);
    Edge edge55(55, &vertices[39], &vertices[43]);
    Edge edge56(56, &vertices[39], &vertices[44]);
    Edge edge57(57, &vertices[40], &vertices[44]);
    Edge edge58(58, &vertices[40], &vertices[45]);
    Edge edge59(59, &vertices[41], &vertices[45]);
    Edge edge60(60, &vertices[41], &vertices[46]);
    Edge edge61(61, &vertices[42], &vertices[46]);
    Edge edge62(62, &vertices[43], &vertices[47]);
    Edge edge63(63, &vertices[44], &vertices[48]);
    Edge edge64(64, &vertices[45], &vertices[49]);
    Edge edge65(65, &vertices[46], &vertices[50]);
    Edge edge66(66, &vertices[47], &vertices[51]);
    Edge edge67(67, &vertices[48], &vertices[51]);
    Edge edge68(68, &vertices[48], &vertices[52]);
    Edge edge69(69, &vertices[49], &vertices[52]);
    Edge edge70(70, &vertices[49], &vertices[53]);
    Edge edge71(71, &vertices[50], &vertices[53]);

    edges = {edge0, edge1, edge2, edge3, edge4, edge5, edge6, edge7, edge8, edge9, edge10,
             edge11, edge12, edge13, edge14, edge15, edge16, edge17, edge18, edge19, edge20, edge21,
             edge22, edge23, edge24, edge25, edge26, edge27, edge28, edge29, edge30, edge31, edge32,
             edge33, edge34, edge35, edge36, edge37, edge38, edge39, edge40, edge41, edge42, edge43,
             edge44, edge45, edge46, edge47, edge48, edge49, edge50, edge51, edge52, edge53, edge54,
             edge55, edge56, edge57, edge58, edge59, edge60, edge61, edge62, edge63, edge64, edge65,
             edge66, edge67, edge68, edge69, edge70, edge71};

    // init 19 tiles
    // each tile has 6 vertex and 6 edges

    // tile 0
    vector<Vertex *> vertex_tile0 = {&vertices[0], &vertices[3], &vertices[4], &vertices[7], &vertices[8], &vertices[12]};
    vector<Edge *> edge_tile0 = {&edges[0], &edges[1], &edges[6], &edges[7], &edges[11], &edges[12]};
    Tile tile0(0, vertex_tile0, edge_tile0);
    // tile0.printTile();

    // tile 1
    vector<Vertex *> vertex_tile1 = {&vertices[1], &vertices[4], &vertices[5], &vertices[8], &vertices[9], &vertices[13]};
    vector<Edge *> edge_tile1 = {&edges[0], &edges[3], &edges[7], &edges[8], &edges[13], &edges[14]};
    Tile tile1(1, vertex_tile1, edge_tile1);

    // tile 2
    vector<Vertex *> vertex_tile2 = {&vertices[2], &vertices[5], &vertices[6], &vertices[9], &vertices[10], &vertices[14]};
    vector<Edge *> edge_tile2 = {&edges[4], &edges[5], &edges[8], &edges[9], &edges[15], &edges[16]};
    Tile tile2(2, vertex_tile2, edge_tile2);

    // tile 3
    vector<Vertex *> vertex_tile3 = {&vertices[7], &vertices[11], &vertices[12], &vertices[16], &vertices[17], &vertices[22]};
    vector<Edge *> edge_tile3 = {&edges[10], &edges[11], &edges[18], &edges[19], &edges[24], &edges[25]};
    Tile tile3(3, vertex_tile3, edge_tile3);

    // tile 4
    vector<Vertex *> vertex_tile4 = {&vertices[8], &vertices[12], &vertices[13], &vertices[17], &vertices[18], &vertices[23]};
    vector<Edge *> edge_tile4 = {&edges[12], &edges[13], &edges[19], &edges[20], &edges[26], &edges[27]};
    Tile tile4(4, vertex_tile4, edge_tile4);

    // tile 5
    vector<Vertex *> vertex_tile5 = {&vertices[9], &vertices[13], &vertices[14], &vertices[18], &vertices[19], &vertices[24]};
    vector<Edge *> edge_tile5 = {&edges[14], &edges[15], &edges[20], &edges[21], &edges[28], &edges[29]};
    Tile tile5(5, vertex_tile5, edge_tile5);

    // tile 6
    vector<Vertex *> vertex_tile6 = {&vertices[10], &vertices[14], &vertices[15], &vertices[19], &vertices[20], &vertices[25]};
    vector<Edge *> edge_tile6 = {&edges[16], &edges[17], &edges[21], &edges[22], &edges[30], &edges[31]};
    Tile tile6(6, vertex_tile6, edge_tile6);

    // tile 7
    vector<Vertex *> vertex_tile7 = {&vertices[16], &vertices[21], &vertices[22], &vertices[27], &vertices[28], &vertices[33]};
    vector<Edge *> edge_tile7 = {&edges[23], &edges[24], &edges[33], &edges[34], &edges[39], &edges[40]};
    Tile tile7(7, vertex_tile7, edge_tile7);

    // tile 8
    vector<Vertex *> vertex_tile8 = {&vertices[17], &vertices[22], &vertices[23], &vertices[28], &vertices[29], &vertices[34]};
    vector<Edge *> edge_tile8 = {&edges[25], &edges[26], &edges[34], &edges[35], &edges[41], &edges[42]};
    Tile tile8(8, vertex_tile8, edge_tile8);

    // tile 9
    vector<Vertex *> vertex_tile9 = {&vertices[18], &vertices[23], &vertices[24], &vertices[29], &vertices[30], &vertices[35]};
    vector<Edge *> edge_tile9 = {&edges[27], &edges[28], &edges[35], &edges[36], &edges[43], &edges[44]};
    Tile tile9(9, vertex_tile9, edge_tile9);

    // tile 10
    vector<Vertex *> vertex_tile10 = {&vertices[19], &vertices[24], &vertices[25], &vertices[30], &vertices[31], &vertices[36]};
    vector<Edge *> edge_tile10 = {&edges[29], &edges[30], &edges[36], &edges[37], &edges[45], &edges[46]};
    Tile tile10(10, vertex_tile10, edge_tile10);

    // tile 11
    vector<Vertex *> vertex_tile11 = {&vertices[20], &vertices[25], &vertices[26], &vertices[31], &vertices[32], &vertices[37]};
    vector<Edge *> edge_tile11 = {&edges[31], &edges[32], &edges[37], &edges[38], &edges[47], &edges[48]};
    Tile tile11(11, vertex_tile11, edge_tile11);

    // tile 12
    vector<Vertex *> vertex_tile12 = {&vertices[28], &vertices[33], &vertices[34], &vertices[38], &vertices[39], &vertices[43]};
    vector<Edge *> edge_tile12 = {&edges[40], &edges[41], &edges[49], &edges[50], &edges[54], &edges[55]};
    Tile tile12(12, vertex_tile12, edge_tile12);

    // tile 13
    vector<Vertex *> vertex_tile13 = {&vertices[29], &vertices[34], &vertices[35], &vertices[39], &vertices[40], &vertices[44]};
    vector<Edge *> edge_tile13 = {&edges[42], &edges[43], &edges[50], &edges[51], &edges[56], &edges[57]};
    Tile tile13(13, vertex_tile13, edge_tile13);

    // tile 14
    vector<Vertex *> vertex_tile14 = {&vertices[30], &vertices[35], &vertices[36], &vertices[40], &vertices[41], &vertices[45]};
    vector<Edge *> edge_tile14 = {&edges[44], &edges[45], &edges[51], &edges[52], &edges[58], &edges[59]};
    Tile tile14(14, vertex_tile14, edge_tile14);

    // tile 15
    vector<Vertex *> vertex_tile15 = {&vertices[31], &vertices[36], &vertices[37], &vertices[41], &vertices[42], &vertices[46]};
    vector<Edge *> edge_tile15 = {&edges[46], &edges[47], &edges[52], &edges[53], &edges[60], &edges[61]};
    Tile tile15(15, vertex_tile15, edge_tile15);

    // tile 16
    vector<Vertex *> vertex_tile16 = {&vertices[39], &vertices[43], &vertices[44], &vertices[47], &vertices[48], &vertices[51]};
    vector<Edge *> edge_tile16 = {&edges[55], &edges[56], &edges[62], &edges[63], &edges[66], &edges[67]};
    Tile tile16(16, vertex_tile16, edge_tile16);

    // tile 17
    vector<Vertex *> vertex_tile17 = {&vertices[40], &vertices[44], &vertices[45], &vertices[48], &vertices[49], &vertices[52]};
    vector<Edge *> edge_tile17 = {&edges[57], &edges[58], &edges[63], &edges[64], &edges[68], &edges[69]};
    Tile tile17(17, vertex_tile17, edge_tile17);

    // tile 18
    vector<Vertex *> vertex_tile18 = {&vertices[41], &vertices[45], &vertices[46], &vertices[49], &vertices[50], &vertices[53]};
    vector<Edge *> edge_tile18 = {&edges[59], &edges[60], &edges[64], &edges[65], &edges[70], &edges[71]};
    Tile tile18(18, vertex_tile18, edge_tile18);

    tiles = {tile0, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10,
             tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18};
    InitResourcesAndNumbers();
    InitVerticesResources();
    InitVerticesAdjacencyEdges();
}



Vertex* Board::getVertex(int id_num)
{
    for (size_t i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].getId() == id_num)
        {
            return &vertices[i];
        }
    }
    return NULL;
}

Edge* Board::getEdge(int id_num)
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i].getId() == id_num)
        {
            return &edges[i];
        }
    }
    return NULL;
}

void Board::InitResourcesAndNumbers()
{
    // array of resources
    int resources[18] = {WOOD, WOOD, WOOD, WOOD, BRICK, BRICK, BRICK, SHEEP, SHEEP, SHEEP, SHEEP, WHEAT, WHEAT, WHEAT, WHEAT, IRON, IRON, IRON};
    // set desert tile in the middle
    tiles[9].setResource(DESERT);
    tiles[9].setNumber(0);
    // array of numbers
    int numbers[18] = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    // shuffle the resources
    // set random resource and number for each tile,
    // each resource and number will be used only once
    for (int i = 0; i < 9; i++)
    {
        int random1 = rand() % 18;
        while (resources[random1] == -1)
        {
            random1 = rand() % 18;
        }
        tiles[i].setResource(resources[random1]);
        int random2 = rand() % 18;
        while (numbers[random2] == -1)
        {
            random2 = rand() % 18;
        }
        tiles[i].setNumber(numbers[random2]);
        resources[random1] = -1;
        numbers[random2] = -1;
    }
    for (int i = 10; i < 19; i++)
    {
        int random1 = rand() % 18;
        while (resources[random1] == -1)
        {
            random1 = rand() % 18;
        }
        tiles[i].setResource(resources[random1]);
        int random2 = rand() % 18;
        while (numbers[random2] == -1)
        {
            random2 = rand() % 18;
        }
        tiles[i].setNumber(numbers[random2]);
        resources[random1] = -1;
        numbers[random2] = -1;
    }

    // check that all resources and numbers are used
    //  for (int i =0 ; i < 18; i++){
    //      cout << "numbers " << numbers[i]
    //      << ", resource: " << resources[i] << " number: "<< endl;
    //  }
}

void Board::printBoard()
{
    for (size_t i = 0; i < 19; i++)
    {
        tiles[i].printTile();
        cout << endl;
    }
}

void Board::InitVerticesResources()
{
    for (size_t i = 0; i < 19; i++)
    {
        int resource = tiles[i].getResource();
        for (size_t j = 0; j < tiles[i].getVertices().size(); j++)
        {
            tiles[i].getVertices()[j]->addResource(resource);
        }
    }
}

void Board::InitVerticesAdjacencyEdges()
{
    vertices[0].addEdges({&edges[0],&edges[1]});
    vertices[1].addEdges({&edges[2],&edges[3]});
    vertices[2].addEdges({&edges[4],&edges[5]});
    vertices[3].addEdges({&edges[0],&edges[6]});
    vertices[4].addEdges({&edges[1],&edges[7],&edges[2]});
    vertices[5].addEdges({&edges[3],&edges[8],&edges[4]});
    vertices[6].addEdges({&edges[5],&edges[9]});
    vertices[7].addEdges({&edges[6],&edges[10],&edges[11]});
    vertices[8].addEdges({&edges[7],&edges[12],&edges[13]});
    vertices[9].addEdges({&edges[8],&edges[14],&edges[15]});
    vertices[10].addEdges({&edges[9],&edges[16],&edges[17]});
    vertices[11].addEdges({&edges[10],&edges[18]});
    vertices[12].addEdges({&edges[11],&edges[19],&edges[12]});
    vertices[13].addEdges({&edges[13],&edges[20],&edges[14]});
    vertices[14].addEdges({&edges[15],&edges[21],&edges[16]});
    vertices[15].addEdges({&edges[17],&edges[22]});
    vertices[16].addEdges({&edges[18],&edges[23],&edges[24]});
    vertices[17].addEdges({&edges[19],&edges[25],&edges[26]});
    vertices[18].addEdges({&edges[20],&edges[27],&edges[28]});
    vertices[19].addEdges({&edges[21],&edges[29],&edges[30]});
    vertices[20].addEdges({&edges[22],&edges[31],&edges[32]});
    vertices[21].addEdges({&edges[23],&edges[33]});
    vertices[22].addEdges({&edges[24],&edges[34],&edges[25]});
    vertices[23].addEdges({&edges[26],&edges[35],&edges[27]});
    vertices[24].addEdges({&edges[28],&edges[36],&edges[29]});
    vertices[25].addEdges({&edges[30],&edges[37],&edges[31]});
    vertices[26].addEdges({&edges[32],&edges[38]});
    vertices[27].addEdges({&edges[33],&edges[39]});
    vertices[28].addEdges({&edges[34],&edges[40],&edges[41]});
    vertices[29].addEdges({&edges[35],&edges[42],&edges[43]});
    vertices[30].addEdges({&edges[36],&edges[44],&edges[45]});
    vertices[31].addEdges({&edges[37],&edges[46],&edges[47]});
    vertices[32].addEdges({&edges[38],&edges[48]});
    vertices[33].addEdges({&edges[39],&edges[49],&edges[40]});
    vertices[34].addEdges({&edges[41],&edges[50],&edges[42]});
    vertices[35].addEdges({&edges[43],&edges[51],&edges[44]});
    vertices[36].addEdges({&edges[45],&edges[52],&edges[46]});
    vertices[37].addEdges({&edges[47],&edges[53]});
    vertices[38].addEdges({&edges[49],&edges[54]});
    vertices[39].addEdges({&edges[50],&edges[55],&edges[56]});
    vertices[40].addEdges({&edges[51],&edges[57],&edges[58]});
    vertices[41].addEdges({&edges[52],&edges[59],&edges[60]});
    vertices[42].addEdges({&edges[53],&edges[61]});
    vertices[43].addEdges({&edges[54],&edges[62],&edges[55]});
    vertices[44].addEdges({&edges[56],&edges[63],&edges[57]});
    vertices[45].addEdges({&edges[58],&edges[64],&edges[59]});
    vertices[46].addEdges({&edges[60],&edges[65]});
    vertices[47].addEdges({&edges[62],&edges[66]});
    vertices[48].addEdges({&edges[63],&edges[67],&edges[68]});
    vertices[49].addEdges({&edges[64],&edges[69],&edges[70]});
    vertices[50].addEdges({&edges[65],&edges[71]});
    vertices[51].addEdges({&edges[66],&edges[67]});
    vertices[52].addEdges({&edges[68],&edges[69],&edges[70]});
    vertices[53].addEdges({&edges[71]});

}
