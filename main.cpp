#include <nodepp/nodepp.h>
#include <express/http.h>
#include <nodepp/json.h>
#include <nodepp/ws.h>

namespace rl {
    #include <raylib/raylib.h>
    #include <raylib/raygl.h>
    #include <raylib/raymath.h>
}

using namespace nodepp;

ptr_t<rl::Vector3> pos = new rl::Vector3({ 0,0,0 });

event_t<float> onLoop ;
event_t<>      onDraw ;
event_t<>      onClose;

void start_server(){
    
    auto app = express::http::add();

    app.USE( express::http::file("./view") );

    auto srv = app.listen( "0.0.0.0", 8000, [=]( socket_t ){
        console::log( "http://localhost:8000" );
    }); ws::server( srv );

    srv.onConnect([=]( ws_t cli ){

        console::log( "connected" );

        cli.onData([=]( string_t raw ){ try {

            auto data = json::parse( raw );
            console::log( "->", raw );
            
            pos->x = string::to_float( data["x"].as<string_t>() );
            pos->y = string::to_float( data["y"].as<string_t>() );
            pos->z = string::to_float( data["z"].as<string_t>() );

        } catch( except_t ) {} });

        cli.onDrain([=](){
            console::log( "disconnected" );
        });

    });

}

void start_game(){

    rl::InitWindow( 800, 600, "Game" ); rl::SetTargetFPS( 60 );
    rl::Texture2D txt = rl::LoadTexture ( "./img.png" );
    ptr_t<rl::Vector3> vc3 = new rl::Vector3({ 0,0,0 });

    onDraw([=](){
        rl::ClearBackground( rl::BLACK );
        rl::DrawTextureEx( txt, rl::Vector2({ vc3->x, vc3->y }), vc3->z, 1.0f, rl::WHITE );
    });

    onLoop([=]( float delta ){ 
        *vc3   += *pos * rl::Vector3({ 1, 1, 0 }); 
         vc3->z =  pos->z * RAD2DEG;
    });

}

void onMain(){

    start_game  ();
    start_server();

    onClose.once([=](){ 
        rl::CloseWindow(); 
        process::exit(1);
    });

    process::add( coroutine::add( COROUTINE(){
    coBegin

      while( !rl::WindowShouldClose() ){ 
    
        onLoop.emit( rl::GetFrameTime() );
        rl::BeginDrawing(); onDraw.emit(); rl::EndDrawing();
        
      coNext; } onClose.emit();

    coFinish
    }));

}