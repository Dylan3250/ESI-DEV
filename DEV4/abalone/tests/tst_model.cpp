#include <catch.hpp>
#include <model.h>

using namespace abalone;

TEST_CASE("Tests moves Line in board", "[board][moveLine]") {
    Board board;

    SECTION("Move droite 2 balles (C2C3)") {
        Position posStarted {6,1};//C2
        Position posDestination {6,2};//c3
        Position posDestinationPushed {6,3};//c4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move gauche 2 balles G5G4") {
        Position posStarted {2,4};//G5
        Position posDestination {2,3};//G4
        Position posDestinationPushed {2,2};//G3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move haut 2 balles b4c5") {
        Position posStarted {7,3};//b4
        Position posDestination {6,4};//c5
        Position posDestinationPushed {5,5};//d6
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move sud 2 balles c5b5") {
        board.moveLine({8,4},{8,3});//A5 a4
        Position posStarted {6,4};//c5
        Position posDestination {7,4};//b5
        Position posDestinationPushed {8,4};//A5
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move nord-gauche 2 balles a3b2") {
        board.moveLine({8,1},{8,2}); //a2a3
        Position posStarted {8,2};//a3
        Position posDestination {7,1};//b2
        Position posDestinationPushed {6,0};//c1
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move nord-droite 2 balles b1c2") {
        Position posStarted {7,0};//b1
        Position posDestination {6,1};//c2
        Position posDestinationPushed {5,2};//d3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move sud droite 2 balles c2b3 ") {
        board.moveLine({8,3},{8,4}); //a4a5
        Position posStarted {6,1};//c2
        Position posDestination{7,2} ;//b3
        Position posDestinationPushed {8,3};//a4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move sud gauche 2 balles h5g4") {
        Position posStarted {1,4};//h5
        Position posDestination {2,3};//g4
        Position posDestinationPushed {3,2};//f3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas nord 3 balle A1b1") {
        board.moveLine({6,1},{6,0});//c2c1
        Position posStarted {8,0};//A1
        Position posDestination {7,0};//B1
        Position posDestinationPushed2 {6,0};//c1
        Position posDestinationPushed3 {5,0};//d1
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas nord-gauche 3 balle A5B4") {
        board.moveLine({6,2},{6,1});
        board.moveLine({6,5},{6,4});
        board.moveLine({6,4},{6,3});
        Position posStarted {8,4};//A5
        Position posDestination {7,3};//b4
        Position posDestinationPushed2 {6,2};//c3
        Position posDestinationPushed3 {5,1};//D2
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas gauche 3 balle g6g5") {
        board.moveLine({1,5},{2,5}); //h6g6
        Position posStarted {2,5};//g6
        Position posDestination {2,4};//g5
        Position posDestinationPushed2 {2,3};//g4
        Position posDestinationPushed3 {2,2};//g3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas sud 3 balle I5H5") {
        Position posStarted {0,4};//I5
        Position posDestination {1,4};//H5
        Position posDestinationPushed2 {2,4};//G5
        Position posDestinationPushed3 {3,4};//F5
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas droite 3 balle c4c5") {
        board.moveLine({7,3},{6,3}); //B4C4
        Position posStarted {6,3};//c4
        Position posDestination {6,4};//c5
        Position posDestinationPushed2 {6,5};//c6
        Position posDestinationPushed3 {6,6};//c7
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas droite-haut 3 balle a4b5") {
        Position posStarted {8,3};//a4
        Position posDestination{7,4} ;//b5
        Position posDestinationPushed2{6,5}; //c6
        Position posDestinationPushed3 {5,6} ;//D7
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("Move cas gauche-bas 3 balle i9h8") {

        Position posStarted {0,8};//i9
        Position posDestination {1,7};//h8
        Position posDestinationPushed2 {2,6};//g7
        Position posDestinationPushed3 {3,5};//f6
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION("blocage 1vs1 A4A3") {
        board.moveLine({8,1},{8,2});//a2a3
        Position posStarted {8,3};//A4
        Position posDestination {8,2};//A3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::BLOCKED);
    }

    SECTION("blocage 2vs2 a4a3") {
        board.moveLine({8,4},{8,3}); //a5a4
        Position posStarted {8,3};//a4
        Position posDestination {8,2};//a3
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::BLOCKED);
    }

    SECTION("blocage 3vs3 B1B2") {
        Position posStarted {7,0};//B1
        Position posDestination {7,1};//B2
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::BLOCKED);
    }

    SECTION("blocage push 4ball ") {
        board.moveLine({7,5},{6,5}); //b6c6
        board.moveLine({8,3},{8,2});//a4a3
        Position posStarted {8,2};//a3
        Position posDestination {7,3};//B4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::BLOCKED);
    }

    SECTION ("bloage 4vs1"){
        board.moveLine({7,5},{6,5});//b6c6
        board.moveLine({8,3},{8,2});//a4a3
        board.moveLine({8,2},{7,3});//a3b4
        board.moveLine({1,6},{2,6});//h7g7
        board.moveLine({2,6},{3,6});//g7f7
        Position posStarted {8,2};//a3
        Position posDestination {7,3};//b4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::BLOCKED);
    }

    SECTION("push 2vs1"){
        board.moveLine({6,2},{6,3}); //c3c4
        Position posStarted {8,3};//a4
        Position posDestination {7,3};//b4
        Position posDestinationPushed {6,3};//c4
        Position posDestinationPushedadverse {5,3};//d4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushedadverse)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::PUSHED);
    }

    SECTION("push 3vs2"){
        board.moveLine({7,0},{6,0});//b1c1
        Position posStarted {7,5};//b6
        Position posDestination {7,4};//b5
        Position posDestinationPushed1{7,3};//b4
        Position posDestinationPushed2 {7,2};//b3
        Position posDestinationPushed3{7,1};//b2
        Position posDestinationPushed4{7,0};//b1
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed1)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posDestinationPushed4)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::PUSHED);
    }

    SECTION("push 3vs1"){
        board.moveLine({7,1},{6,1});//b2c2
        board.moveLine({7,0},{6,0});//b1c1
        Position posStarted {7,5};// b6
        Position posDestination {7,4};//b5
        Position posDestinationPushed1{7,3};//b4
        Position posDestinationPushed2 {7,2};//b3
        Position posDestinationPushed3 {7,1};//b2
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed1)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posDestinationPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::PUSHED);
    }

    SECTION("fairetombersabille"){
        Position posStarted {1,8};//h9
        Position posDestination {0,8};//i9
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::SELF_FALLEN);
    }

    SECTION("Cas normal 3vs2 tombe gauche"){
        board.moveLine({7,0},{6,0}); // b1c1
        board.moveLine({7,5},{7,4}); //b6b5
        Position posStarted {7,4};//b5
        Position posDestination{7,3};//b4
        Position posPushed{7,2};//b3
        Position posPushed2{7,1};//b2
        Position posPushed3 {7,0};//b1
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("Cas normal 3vs2 tombe droite"){
        board.moveLine({7,5},{6,5}); //b6c6
        board.moveLine({7,2},{8,2}); //b3a3
        Position posStarted {8,0};//a1
        Position posDestination{8,1};//a2
        Position posPushed{8,2};//a3
        Position posPushed2{8,3};//a4
        Position posPushed3 {8,4};//a5
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("cas normal 3vs2 tombe sud droite"){
        board.moveLine({8,0},{7,1}); //a1b2
        board.moveLine({7,0},{6,1}); //b1c2
        board.moveLine({7,2},{6,1}); //b3c2
        board.moveLine({6,1},{5,2}); //c2d3
        board.moveLine({5,2},{4,2}); //d3e3
        board.moveLine({4,3},{3,3}); //e4f4
        board.moveLine({3,3},{3,2}); //f4f3
        board.moveLine({3,2},{3,1}); //f3f2
        Position posStarted {3,1};//f2
        Position posDestination{4,2};//e3
        Position posPushed{5,3};//d4
        Position posPushed2{6,4};//c5
        Position posPushed3{7,5};//b6
        ActionStatus result{ board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("cas normal 2vs1 tombe sud droite"){
        board.moveLine({8,0},{7,1}); //a1b2
        board.moveLine({7,0},{6,1}); //b1c2
        board.moveLine({7,2},{6,1}); //b3c2
        board.moveLine({6,1},{5,2}); //c2d3
        board.moveLine({5,2},{4,2}); //d3e3
        board.moveLine({4,3},{3,3}); //e4f4
        board.moveLine({3,3},{3,2}); //f4f3
        board.moveLine({3,2},{3,1}); //f3f2
        board.moveLine({3,1},{4,2});//f2e3
        Position posStarted {5,3}; //d4
        Position posDestination{6,4};//c5
        ActionStatus result{ board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("cas normal 3vs2 tombe sud "){
        board.moveLine({6,1},{6,2}); //c2c3
        board.moveLine({8,0},{8,1}); //a1a2
        board.moveLine({7,1},{6,2}); //b2c3
        board.moveLine({6,2},{5,2}); //c3d3
        board.moveLine({5,2},{4,3}); //d3e4
        Position posStarted {4,3};//e4
        Position posDestination{5,3};//d4
        Position posPushed{6,3};//c4
        Position posPushed2{7,3};//b4
        Position posPushed3{8,3};//a4
        ActionStatus result{ board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("cas normal 2vs1 tombe sud "){
        board.moveLine({6,1},{6,2}); //c2c3
        board.moveLine({8,0},{8,1}); //a1a2
        board.moveLine({7,1},{6,2}); //b2c3
        board.moveLine({6,2},{5,2}); //c3d3
        board.moveLine({5,2},{4,3}); //d3e4
        board.moveLine( {4,3},{5,3});//e4d4
        Position posStarted{5,3};//d4
        Position posDestination{6,3};//c4
        ActionStatus result{ board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);

    }

    SECTION("cas normal 3vs2 tombe sud-gauche "){
        board.moveLine ({6,2},{6,1}) ; //c3c2
        board.moveLine ({6,5},{6,4}) ; //c6c5
        board.moveLine  ({0,4},{1,4}); //i5h5
        board.moveLine ({8,4},{7,4}) ; //a5b5
        board.moveLine({3,4},{4,5}) ; //f5e6
        Position posStarted {4,5};//e6
        Position posDestination{5,4}; //d5
        Position posPushed{6,3};//c4
        Position posPushed2{7,2};//b3
        Position posPushed3 {8,1};//a2
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION ("cas normal 2v1 tombe sud-gauche"){
        board.moveLine ({6,2},{6,1}) ; //c3c2
        board.moveLine ({6,5},{6,4}) ; //c6c5
        board.moveLine  ({0,4},{1,4}); //i5h5
        board.moveLine ({8,4},{7,4}) ; //a5b5
        board.moveLine({3,4},{4,5}) ; //f5e6
        board.moveLine( {4,5},{5,4});//e6d5
        Position posDestination{6,3};//c4
        Position posStarted{5,4};//d5
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("Cas normal 3vs2 tombe nord-droite"){
        board.moveLine ({2,6},{2,7}) ; //g7g8
        board.moveLine ({2,3},{2,4}) ; //g4g5
        board.moveLine ({0,4},{1,4}); //i5h5
        board.moveLine ({2,4},{3,3}) ; //g5f4
        board.moveLine({3,3},{4,4}) ; //f4e5
        board.moveLine({4,4},{4,3}) ; //e5e4
        Position posStarted {4,3};//e4
        Position posDestination{3,4}; //f5
        Position posPushed{2,5};//g6
        Position posPushed2{1,6};//h7
        Position posPushed3 {0,7};//i8
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::WHITE);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::BLACK);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("Cas normal 2vs1 tombe nord-droite"){
        board.moveLine ({2,6},{2,7}) ; //g7g8
        board.moveLine ({2,3},{2,4}) ; //g4g5
        board.moveLine ({0,4},{1,4}); //i5h5
        board.moveLine ({2,4},{3,3}) ; //g5f4
        board.moveLine({3,3},{4,4}) ; //f4e5
        board.moveLine({4,4},{4,3}) ; //e5e4
        board.moveLine({4,3},{3,4}) ; //e4f5
        Position posStarted {2,5};//g6
        Position posDestination{1,6}; //h7
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("Cas normal 3vs2 tombe nord"){
        board.moveLine ({0,7},{1,6}) ; //i8h7
        board.moveLine ({0,8},{1,7}) ; //i9h8
        board.moveLine ({1,8},{2,7}); //h9g8
        board.moveLine ({3,6},{4,5}) ; //f7e6
        Position posStarted {4,5};//e6
        Position posDestination{3,5}; //f6
        Position posPushed{2,5};//g6
        Position posPushed2{1,5};//h6
        Position posPushed3 {0,5};//i6
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION ("Cas normal 2vs1 tombe nord"){
        board.moveLine ({0,7},{1,6}) ; //i8h7
        board.moveLine ({0,8},{1,7}) ; //i9h8
        board.moveLine ({1,8},{2,7}); //h9g8
        board.moveLine ({3,6},{4,5}) ; //f7e6
        board.moveLine({4,5},{3,5}); //e6f6
        Position posStarted {2,5};//g6
        Position posDestination{1,5}; //h6
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("Cas normal 3vs2 tombe nord-gauche"){
        board.moveLine ({2,7},{2,6}) ; //g8g7
        board.moveLine ({2,6},{3,5}) ; //g7f6
        board.moveLine ({2,4},{2,3}); //g5g4
        board.moveLine ({2,5},{2,4}) ; //g6g5
        board.moveLine ({2,2},{2,3}) ; //g3g4
        board.moveLine ({0,7},{1,7}) ; //i8h8
        board.moveLine ({2,5},{3,5}); //g6f6
        board.moveLine ({4,5},{4,6}) ; //e6e7
        board.moveLine ({1,7},{2,7}) ; //h8g8
        board.moveLine ({2,7},{3,7}) ; //g8f8
        board.moveLine ({4,7},{5,7}); //e8d7
        Position posStarted {5,7};//d7
        Position posDestination{4,6}; //e7
        Position posPushed{3,5};//f6
        Position posPushed2{2,4};//g5
        Position posPushed3 {1,3};//h4
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(board.at(posDestination)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed2)->ball()->color() == Color::BLACK);
        REQUIRE(board.at(posPushed3)->ball()->color() == Color::WHITE);
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION ("Cas normal 2vs1 tombe nord"){
        board.moveLine ({2,7},{2,6}) ; //g8g7
        board.moveLine ({2,6},{3,5}) ; //g7f6
        board.moveLine ({2,4},{2,3}); //g5g4
        board.moveLine ({2,5},{2,4}) ; //g6g5
        board.moveLine ({2,2},{2,3}) ; //g3g4
        board.moveLine ({0,7},{1,7}) ; //i8h8
        board.moveLine ({2,5},{3,5}); //g6f6
        board.moveLine ({4,5},{4,6}) ; //e6e7
        board.moveLine ({1,7},{2,7}) ; //h8g8
        board.moveLine ({2,7},{3,7}) ; //g8f8
        board.moveLine ({4,7},{5,7}); //e8d7
        board.moveLine ( {5,7},{4,6});//d7e7
        Position posStarted {3,5};//f6
        Position posDestination{2,4}; //g5
        ActionStatus result { board.moveLine(posStarted, posDestination) };
        REQUIRE(result == ActionStatus::FALLEN);
    }

    SECTION("pas de ball") {
        REQUIRE_THROWS_WITH(board.moveLine({4,3},{4,4}),"Any ball on the started position.");
    }

}

TEST_CASE("Tests moves Lateral in board,[board][moveLateral]"){
    Board board ;
    SECTION ("C2C3D2 (2balles)nord "){
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,2};//c3
        Position PosLateral {5,1}; //D2
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("C2C4D2 (3balles)nord "){
        board.moveLine({7,2},{6,3});//b3c4
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,3};//c4
        Position PosLateral {5,1}; //D2
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("C2C3d1(2balles) nord-gauche"){
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,2};//c3
        Position PosLateral {5,0}; //D3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("C2C4D1 (3balles)nord-gauche"){
        board.moveLine({7,2},{6,3});//b3c4
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,3};//c4
        Position PosLateral {5,0}; //D1
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION ("C2C3d3 (2balles)nord-droite"){
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,2};//c3
        Position PosLateral {5,2}; //D3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("C2C4D3 (3balles) nord-droite"){
        board.moveLine({7,2},{6,3});//b3c4
        Position PosStarted {6,1}; //C2
        Position PosDestination {6,3};//c4
        Position PosLateral {5,2}; //D3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d2d3c2(2balles) sud"){
        board.moveLateral({6,1},{6,2},{5,1});//c2c3d2
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,2};//d3
        Position PosLateral {6,1}; //c2
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d2d4c2 (3balles) sud"){
        board.moveLateral({6,1},{6,2},{5,1});
        board.moveLine({7,2},{6,2});//b3c3
        board.moveLine({6,2},{5,3});//c3d4
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,3};//d4
        Position PosLateral {6,1}; //c2
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }

    SECTION ("d2d3c1 (2balles)sud-gauche"){
        board.moveLateral({6,1},{6,2},{5,1});
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,2};//d3
        Position PosLateral {6,0}; //c1
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d2d4c1 (3balles) sud-gauche"){
        board.moveLateral({6,1},{6,2},{5,1});
        board.moveLine({7,2},{6,2});//b3c3
        board.moveLine({6,2},{5,3});//c3d4
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,3};//d4
        Position PosLateral {6,0}; //c1
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d2d3c3 (2balles)sud-droite"){
        board.moveLateral({6,1},{6,2},{5,1});
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,2};//d3
        Position PosLateral {6,2}; //c3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d2d4c3 (3balles) sud-droite"){
        board.moveLateral({6,1},{6,2},{5,1});
        board.moveLine({7,2},{6,2});//b3c3
        board.moveLine({6,2},{5,3});//c3d4
        board.moveLine({6,4},{6,5});//c5c6
        Position PosStarted {5,1}; //d2
        Position PosDestination {5,3};//d4
        Position PosLateral {6,2}; //c3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("c3d3d4 (2ballesvertical) nord-droite"){
        board.moveLine({6,1},{5,2});//c2d3
        Position PosStarted {6,2}; //c3
        Position PosDestination {5,2};//d3
        Position PosLateral {5,3}; //c4
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d4e4c5 (2ballesvertical) sud-droite"){
        board.moveLine({6,1},{5,2});//c2d3
        board.moveLateral({6,2},{5,2},{5,3});
        board.moveLine({6,4},{6,5});//c5c6
        Position PosStarted {5,3}; //d4
        Position PosDestination {4,3};//e4
        Position PosLateral {6,4}; //c5
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d4e4e3 (2ballesvertical) nord-gauche"){
        board.moveLine({6,1},{5,2});//c2d3
        board.moveLateral({6,2},{5,2},{5,3});
        board.moveLine({6,4},{6,5});//c5c6
        Position PosStarted {5,3}; //d4
        Position PosDestination {4,3};//e4
        Position PosLateral {4,2}; //e3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("d4e4c3 (2ballesvertical) sud-gauche"){
        board.moveLine({6,1},{5,2});//c2d3
        board.moveLateral({6,2},{5,2},{5,3});
        board.moveLine({6,4},{6,5});//c5c6
        Position PosStarted {5,3}; //d4
        Position PosDestination {4,3};//e4
        Position PosLateral {6,2}; //c3
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::MOVED);
    }
    SECTION ("b3c4a4 bloquage sud-droite"){
        board.moveLine({6,1},{6,2});//c3c4
        board.moveLine({6,4},{6,5});//c5c6
        Position PosStarted {7,2}; //b3
        Position PosDestination {6,3};// c4
        Position PosLateral {8,3}; //a4
        ActionStatus result {board.moveLateral(PosStarted,PosDestination,PosLateral)};
        REQUIRE(result == ActionStatus::BLOCKED);
    }

}

TEST_CASE("Tests conversionAbaPro", "[board][conversion]") {
    Board board;

    SECTION("cas normale conversion") {
        const std::string ABACoord = "I5";
        Position exceptedResult {0,4};
        Position result {board.convertABAToCoord(ABACoord)};
        REQUIRE(result == exceptedResult);
    }
    SECTION("Coordonnée inexistante"){
        REQUIRE_THROWS_WITH(board.convertABAToCoord("I4"),
                            "The ABA-PRO coordinate is not valid.");
    }

    SECTION("cas invalide : lettre ok mais chiffre égale à 0") {
        REQUIRE_THROWS_WITH(board.convertABAToCoord("I0"),
                            "The ABA-PRO coordinate is not valid.");
    }

    SECTION("cas invalide : dépassement de la taille abaPro") {
        REQUIRE_THROWS_WITH(board.convertABAToCoord("I55"),
                            "The ABA-PRO coordinate cannot be greater than 2.");
    }

    SECTION("cas invalide : lettre inexistante") {
        REQUIRE_THROWS_WITH(board.convertABAToCoord("Z4"),
                            "The ABA-PRO coordinate is not valid.");
    }

}

TEST_CASE("Tests Direction", "[board][direction]") {
    Board board;
    Position ABACoord1  {3,3};

    SECTION("cas valide : droite (est) F4->F5") {
        Position ABACoord2  {3,4};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position expected  {0, 1};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : gauche (west) F4->F3") {
        Position ABACoord2 {3,2};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position  expected {0, -1};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : haut (north) F4->G4") {
        Position ABACoord2 {2,3};
        Position result   = board.direction(ABACoord1,ABACoord2);
        Position  expected {-1, 0};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : bas (south) F4->E4") {
        Position ABACoord2 {4,3};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position  expected {1, 0};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : nord-gauche (north west) F4->G3") {
        Position ABACoord2 {2,2};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position expected  {-1, -1};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : nord-droite (north est) F4->G5") {
        Position ABACoord2 {2,4};
        Position result   = board.direction(ABACoord1,ABACoord2);
        Position  expected {-1, 1};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : sud-droite (south west) F4->E5") {
        Position ABACoord2 {4,4};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position expected  {1, 1};
        REQUIRE(result == expected);
    }

    SECTION("cas valide : sud-gauche (south est) F4->E3") {
        Position ABACoord2 {4,2};
        Position result  = board.direction(ABACoord1,ABACoord2);
        Position expected  {1, -1};
        REQUIRE(result == expected);
    }

    SECTION("cas invalide : F4->E6") {
        Position ABACoord2 {4,5};
        REQUIRE_THROWS_WITH(board.direction(ABACoord1,ABACoord2),
                            "Bad movement to make displacement.");
    }
    SECTION("cas invalide (same coordonate): F4->F4") {
        Position ABACoord2 {3,3};
        REQUIRE_THROWS_WITH(board.direction(ABACoord1,ABACoord2),
                            "Bad movement to make displacement.");
    }
    SECTION("cas invalide (notinside) : F4->I10") {
        Position ABACoord2 {0,9};
        REQUIRE_THROWS_WITH(board.direction(ABACoord1,ABACoord2),
                            "Bad movement to make displacement.");
    }
    SECTION("cas invalide (coordonate not exist) : I0->H0") {
        Position ABACoord {0,0};
        Position ABACoord2 {1,0};
        REQUIRE_THROWS_WITH(board.direction(ABACoord1,ABACoord2),
                            "Bad movement to make displacement.");
    }

}
