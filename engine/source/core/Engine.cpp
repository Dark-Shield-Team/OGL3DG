//______  _______ _______ _______ _______ _______
//|     \ |______    |    |______ |_____| |  |  |
//|_____/.______| .  |    |______ |     | |  |  |
// Copyright (c) 2020 Dark Shield Team. All rights reserved.
// Created by moonlin on 006 06.09.20 at 20:46.

#include "Engine.h"


Engine::Engine(Game *g, Window *pwindow) :
    game(g), window(pwindow) {
    this->game->setEngine(this);
    glfwSetErrorCallback(&Log::glfwError);
}

auto Engine::run() -> int {
    if (game == nullptr) // if game not added to engine
        Log.error("game is nullptr. Aborting..");
    else
        Log.info("Engine started successfully");
    window->init();


    game->Init();

    while (!window->isCloseRequested()) {
        Time.update();

        window-> update();
        camera->updateMatrices(window->getAspect());

        this->game->ProcessInput(Time.getDelta());
        this->game->Update(Time.getDelta());

        Window::clear();
        this->game->Render();

        renderer->draw(camera);
        window->render();
    }

    game->Destroy();
    return 0;
}


