import turtle
import os
import random

#setup the screen

wn = turtle.Screen()
wn.bgcolor("black")
wn.title("Space Invaders")


#draw border
border = turtle.Turtle()
border.ht()
border.setposition(-900,700)
border.speed(0)
border.pen(fillcolor="white", pencolor="white", pensize = 4)
border.pendown()
border.goto(-900,-700)
border.goto(900,-700)
border.goto(900,700)
border.goto(-900,700)

#create the player turtle
player = turtle.Turtle()
player.setposition(0,-645)
player.tilt(90)
player.color("light blue")
player.penup()
player.shape("triangle")
player.speed(0)

playerspeed = 15


#create the enemy
enemy = turtle.Turtle()
enemy.setposition(0,0)
enemy.color("white")
enemy.penup()
enemy.shape("turtle")


#move player
def move_left():
    x = player.xcor()
    x -= playerspeed
    if x <-850:
        x = -850
    player.setx(x)

def move_right():
    x = player.xcor()
    x += playerspeed
    if x >850:
        x = 850
    player.setx(x)

def shoot_bullet():
    x = player.xcor()
    y = player.ycor()
    bullet = turtle.Turtle()
    bullet.setposition(x,y)
    bullet.shape("circle")
    bullet.color("white")
    bullet.penup()
    bullet.seth(90)
    bullet.speed(2)
    y = bullet.ycor()
    while y < 700:
        y += 15
        bullet.sety(y)
        print(y)
        if bullet.pos() == enemy.pos():
            bullet.reset()
            enemy.reset()
            kill_enemy()
            break
    bullet.reset()

def kill_enemy():
    for i in range (0,361,45):
        explosion = turtle.Turtle()
        #explosion.color("white")
        #explosion.shape("circle")
        explosion.pen(pencolor="white")
        #explosion.resizemode("auto")
        explosion.pensize(1)
        explosion.setposition(0,0)
        explosion.seth(i)
        explosion.fd(100)
        explosion.undo()
        #turtle.dot(5,"white");turtle.setposition(0,0); turtle.pendown(); turtle.seth(i); turtle.fd(50);


#keybindings
wn.listen()
wn.onkeypress(move_left, "Left")
wn.onkeypress(move_right, "Right")
wn.onkeypress(shoot_bullet,"Up")

delay = input("Press enter to finish.")
