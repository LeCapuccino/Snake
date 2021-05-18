// header file with game functions 

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/GL/glut.h"
#include "../include/GL/freeglut.h"

#include "../include/snake.hpp"
#include "../include/entities.hpp"
#include "../include/settings.hpp"

using namespace snake;
using namespace settings;

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace functions {
	int randomic(float lim) {
			srand((unsigned)time(0));

			return rand() % (int)lim;
		}

	void init(float back[7][4], int color) {
		col = randomic(7);

		glClearColor(back[col][0], back[col][1], back[col][2], back[col][3]);
		glShadeModel(GL_FLAT);

		for (float i = 0; i <= (int)unid - 1; i++) {
			for (float j = 0; j <= (int)unid - 1; j++) {
				mesh[(int)i][(int)j] = Point((2 * j) / unid - 1, 1 - (2 * i) / unid);
			}
		}

		seed = Food(unid); seed.pos();
		lead = Head(((int)unid - 1) / 2, ((int)unid - 1) / 2, unid);

		lead.init();

		for (int n = 0; n < quad; n++) {
			foll[n] = Body(((int)unid - 1) / 2, ((int)unid - 1) / 2, unid);
		}
	}

	void reshape(int width, int height) {
		glViewport(0, 0, width, height);

		float aspect = (float)width / (float)height;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if (width >= height) {
			glOrtho(-aspect, aspect, -1 , 1, 1.0, -1.0);
		}
		else {
			glOrtho(-1, 1, -1.0 / aspect, 1.0 / aspect, 1.0, -1.0);
		}
	}

	void draw() {
		for (int n = lead.foods - 1; n >= 0; n--) {
			if (n == 0) {
				foll[n].move(lead.j, lead.i);
			}
			else {
				foll[n].move(foll[n - 1].j, foll[n - 1].i);
			}
		}

		lead.move();

		seed.draw(mesh, foo, col);

		if (lead.dead) {init(back, col);}
		else {
	    	for (int n = 0; n < lead.foods; n++) {
				foll[n].draw(mesh);
			}

			lead.draw(mesh);

			lead.eat(seed.j, seed.i);
			seed.repos(lead.j, lead.i, lead.foods, foll);

			for (int n = 0; n < lead.foods; n++) {
				lead.colision(foll[n].j, foll[n].i);
			}

			if (lead.dead) {init(back, col);}
		}
	}

	void time(int) {
		glutPostRedisplay ();
		glutTimerFunc(seconds, time, 0.0);
	}

	void display() {
    	glClear(GL_COLOR_BUFFER_BIT);
    	draw();
    	glFlush();
	}

	void Keyboard(unsigned char key, int x, int y) {
		switch(key) {
			case 27:
				glutLeaveMainLoop();
				break;

			case 97:                       //left
				lead.left = true;
				lead.right = false;
				lead.up = false;
				lead.down = false;
				break;

			case 100:                      //right
				lead.left = false;
				lead.right = true;
				lead.up = false;
				lead.down = false;
				break;

			case 119:                      //up
				lead.left = false;
				lead.right = false;
				lead.up = true;
				lead.down = false;
				break;

			case 115:                      //down
				lead.left = false;
				lead.right = false;
				lead.up = false;
				lead.down = true;
				break;
		}

		lead.free = true;

		glutPostRedisplay();
	}

	void Special(int key, int x, int y) {
		switch(key) {
			case GLUT_KEY_LEFT:            //left
				lead.left = true;
				lead.right = false;
				lead.up = false;
				lead.down = false;
				break;

			case GLUT_KEY_RIGHT:           //right
				lead.left = false;
				lead.right = true;
				lead.up = false;
				lead.down = false;
				break;

			case GLUT_KEY_UP:              //up
				lead.left = false;
				lead.right = false;
				lead.up = true;
				lead.down = false;
				break;

			case GLUT_KEY_DOWN:            //down
				lead.left = false;
				lead.right = false;
				lead.up = false;
				lead.down = true;
				break;
		}

		lead.free = true;

		glutPostRedisplay();
	}
}

#endif
