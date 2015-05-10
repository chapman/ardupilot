// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *       AP_MotorsOctaQuad.cpp - ArduCopter motors library
 *       Code by RandyMackay. DIYDrones.com
 *
 */

#include "AP_MotorsOctaQuad.h"

// setup_motors - configures the motors for a octa
void AP_MotorsOctaQuad::setup_motors()
{
    // call parent
    AP_MotorsMatrix::setup_motors();

    // hard coded config for supported frames
    if( _flags.frame_orientation == AP_MOTORS_PLUS_FRAME ) {
        // plus frame set-up
        add_motor_coax(AP_MOTORS_MOT_1,    0, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 1, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_2,  -90, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  7, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_3,  180, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 5, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_4,   90, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  3, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_5,  -90, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 8, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_6,    0, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  2, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_7,   90, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 4, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_8,  180, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  6, AP_MOTORS_MATRIX_COAX_LOWER);
    }else if( _flags.frame_orientation == AP_MOTORS_V_FRAME ) {
        // V frame set-up
        add_motor_coax(AP_MOTORS_MOT_1,   45,  0.7981f, 1, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_2,  -45, -0.7981f, 7, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_3, -135,  1.0000f, 5, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_4,  135, -1.0000f, 3, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_5,  -45,  0.7981f, 8, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_6,   45, -0.7981f, 2, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_7,  135,  1.0000f, 4, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_8, -135, -1.0000f, 6, AP_MOTORS_MATRIX_COAX_LOWER);
    }else if( _flags.frame_orientation == AP_MOTORS_H_FRAME ) {
        // H frame set-up - same as X but motors spin in opposite directions
        add_motor_coax(AP_MOTORS_MOT_1,   45, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  1, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_2,  -45, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 7, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_3, -135, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  5, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_4,  135, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 3, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_5,  -45, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  8, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_6,   45, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 2, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_7,  135, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  4, AP_MOTORS_MATRIX_COAX_LOWER);
        add_motor_coax(AP_MOTORS_MOT_8, -135, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 6, AP_MOTORS_MATRIX_COAX_LOWER);
    }else{
        // X frame set-up
        add_motor_coax(AP_MOTORS_MOT_1,   45, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 1, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_2,  -45, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  7, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_3, -135, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 5, AP_MOTORS_MATRIX_COAX_UPPER);
        add_motor_coax(AP_MOTORS_MOT_4,  135, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  3, AP_MOTORS_MATRIX_COAX_UPPER);
        // lower motors will spin contra to top in normal config, or in same direction in new non-contra X8 config
        if ( _flags.frame_orientation == AP_MOTORS_X_FRAME_NON_CONTRA) {
            add_motor_coax(AP_MOTORS_MOT_5,  -45, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  8, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_6,   45, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 2, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_7,  135, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  4, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_8, -135, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 6, AP_MOTORS_MATRIX_COAX_LOWER);
        } else {
            add_motor_coax(AP_MOTORS_MOT_5,  -45, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 8, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_6,   45, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  2, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_7,  135, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 4, AP_MOTORS_MATRIX_COAX_LOWER);
            add_motor_coax(AP_MOTORS_MOT_8, -135, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  6, AP_MOTORS_MATRIX_COAX_LOWER);
        }
    }
}
