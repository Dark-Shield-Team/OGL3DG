//______  _______ _______ _______ _______ _______
//|     \ |______    |    |______ |_____| |  |  |
//|_____/.______| .  |    |______ |     | |  |  |
// Copyright (c) 2020 Dark Shield Team. All rights reserved.
// Created by moonlin on 006 06.09.20 at 20:50.

#include "Camera.h"

Camera::Camera()
{

}

glm::mat4 Camera::getProjViewMat() {
    return ProjectionMatrix * ViewMatrix;
}

void Camera::updateMatrices(float aspect) {
    if(type == cameraType::Perspective) ProjectionMatrix = glm::perspective(glm::radians(FOV), aspect, ddNear, ddFar);
    else if(type == cameraType::Orthographic) ProjectionMatrix = glm::ortho(-FOV, FOV, -FOV, FOV, ddNear, ddFar);
    double pitch = transform-> getPitch();
    double yaw = transform-> getYaw();

    directionSide = glm::vec3(
            cos(pitch) * sin(yaw),
            sin(pitch),
            cos(pitch) * cos(yaw)
    );

    rightSide = glm::vec3 {
            sin(yaw - 1.57f),
            0,
            cos(yaw - 1.57f)
    };

    upSide = glm::cross(-directionSide, rightSide);

    ViewMatrix = glm::lookAt(
            transform->getPosition(),
            transform->getPosition() + directionSide,
            upSide
    );
}

void Camera::forward(float dt) {
    transform->setPosition(transform->getPosition() + directionSide * dt * speed);
}

void Camera::backward(float dt) {
    transform->setPosition(transform->getPosition() - directionSide * dt * speed);
}

void Camera::right(float dt) {
    transform->setPosition(transform->getPosition() + rightSide * dt * speed);
}

void Camera::left(float dt) {
    transform->setPosition(transform->getPosition() - rightSide * dt * speed);
}


void Camera::up(float dt) {
    transform->setPosition(transform->getPosition() + upSide * dt * speed);
}

void Camera::down(float dt) {
    transform->setPosition(transform->getPosition() - upSide * dt * speed);
}

float Camera::getFov() const {
    return FOV;
}

void Camera::setFov(float fov1) {
    Camera::FOV = fov1;
}

float Camera::getSpeed() const {
    return speed;
}

void Camera::setSpeed(float speed1) {
    Camera::speed = speed1;
}

Camera::~Camera() = default;