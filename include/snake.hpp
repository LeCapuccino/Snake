// header file with snake definition 

#include "../include/GL/glut.h"
#include "../include/GL/freeglut.h"

#include "../include/point.hpp"
#include "../include/settings.hpp"

using namespace point;
using namespace settings;

#ifndef SNAKE_HPP
#define SNAKE_HPP

namespace snake {
	class Head {
	public:
		int j;
		int i;

		float unid;

		bool left;
		bool right;
		bool up;
		bool down;

		bool dead;
		bool free;

		int foods;

		float color = 0.96;

		Head() {}
		Head(int j_, int i_, float unid_) : j(j_), i(i_), unid(unid_) {}

		void draw(Point mesh[UNID][UNID]) {
			glColor3f(color, color, color);

			glBegin(GL_POLYGON); 
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y - 2.0 / unid);
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y - 2.0 / unid);
    		glEnd();
		}

		void init() {
			left = false;
			right = false;
			up = false;
			down = false;

			dead = false;

			foods = 0;
		}

		void move() {
			if (left) {
				j--;

				if (j < 0) {dead = true;}
			}

			if (right) {
				j++;

				if (j > unid - 1) {dead = true;}
			}

			if (up) {
				i--;

				if (i < 0) {dead = true;}
			}

			if (down) {
				i++;

				if (i > unid - 1) {dead = true;}
			}
		}

		void eat(int posj, int posi) {
			if (j == posj && i == posi) {
				foods += 1;
			}
		}

		void colision(int posj, int posi) {
			if (j == posj && i == posi) {
				dead = !dead;
			}
		}
	};

	class Body {
	public:
		int j;
		int i;

		float unid;

		float color = 0.94;

		Body() {}
		Body(int j_, int i_, float unid_) : j(j_), i(i_), unid(unid_) {}

		void draw(Point mesh[UNID][UNID]) {
			glColor3f(color, color, color);

			glBegin(GL_POLYGON);
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y - 2.0 / unid);
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y - 2.0 / unid);
    		glEnd();
		}

		void move(int dj, int di) {
			j = dj;
			i = di;
		}
	};
}

#endif