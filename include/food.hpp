// header file with food definition 

#include <cstdlib>
#include <ctime>

#include "../include/snake.hpp"
#include "../include/settings.hpp"

using namespace snake;
using namespace settings;

#ifndef FOOD_HPP
#define FOOD_HPP

namespace food{
	class Food {
	public:
		int j = 24;
		int i = 24;

		float unid;

		Food() {}
		Food(float unid_) : unid(unid_) {}

		void draw(Point mesh[UNID][UNID], float foo_[7][4], int col) {
			glColor3f(foo[col][0], foo[col][1], foo[col][2]);

			glBegin(GL_POLYGON); 
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y);
	    	    glVertex2f(mesh[i][j].x + 2.0 / unid, mesh[i][j].y - 2.0 / unid);
	    	    glVertex2f(mesh[i][j].x, mesh[i][j].y - 2.0 / unid);
    		glEnd(); 
		}

		void pos() {
			srand((unsigned)time(0));

			j = rand() % (int)unid;
			i = rand() % (int)unid;
		}

		void repos(float posj, float posi, int foods, Body foll[QUAD - 1]) {
			if (j == posj && i == posi) {
				while (true) {
					pos();

					if (j == posj && i == posi)  {
							continue;
					}

					for (int n = 0; n < foods; n++) {
						if (j == foll[n].j && i == foll[n].i) {
							continue;
						}
					}

					break;
				}
			}
		}
	};
}

#endif
