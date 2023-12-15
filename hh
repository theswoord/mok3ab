

        // int i = 0;
        // float tanges;
        // int side ; 
        // float disV;
        // float disH;
        // int deptoffield;
        // int mx;
        // int my;
        // int mp;
        // cube->dda.startx = cube->player.x;
        // cube->dda.starty = cube->player.y;
        // cube->dda.endx = cube->player.x + cube->v3.deltax *5 ;
        // cube->dda.endy = cube->player.y + cube->v3.deltay *5 ;
        // cube->v3.rayangle = fixangle(cube->v3.angle + 30)  ;
        // while (i < 60)
        // {
        //     disV=INFINITY;
        //     deptoffield = 0;
        //     side = 0;
        //     /* code */
        //     tanges = tan(d2r(cube->v3.rayangle));
        //     if (cos(d2r(cube->v3.rayangle))> 0.001)
        //     {
        //         cube->v3.rayx = (int)cube->player.x + MINIBLOCK;
        //         cube->v3.rayy = (cube->player.x - cube->v3.rayx) * tanges + cube->player.y ;
        //         cube->v3.xoffset = MINIBLOCK;
        //         cube->v3.yoffset = -cube->v3.xoffset  * tanges;
        //     }
        //     else if(cos(d2r(cube->v3.rayangle)) < -0.001)
        //     {
        //         cube->v3.rayx = (int)cube->player.x - 0.0001;
        //         cube->v3.rayy = (cube->player.x - cube->v3.rayx) * tanges + cube->player.y ;
        //         cube->v3.xoffset = -MINIBLOCK;
        //         cube->v3.yoffset = -cube->v3.xoffset  * tanges;
        //     }
        //     else
        //     {
        //         cube->v3.rayx = cube->player.x;
        //         cube->v3.rayy = cube->player.y;
        //         deptoffield = 8;

        //     }
        //     while (deptoffield < 8)
        //     {
        //         mx =  (int)cube->v3.rayx / MINIBLOCK;
        //         my =  (int)cube->v3.rayy / MINIBLOCK;
        //         // mp = my * WIDTH/MINIBLOCK + mx;
        //         if (cube->map[my][mx]== '1')
        //         {
        //             deptoffield = 8;
        //         }
        //         else
        //         {
        //        cube->v3.rayx += cube->v3.xoffset;
        //        cube->v3.rayy += cube->v3.yoffset;
        //         deptoffield ++;
        //         }
        //     }
        //     // next
        //     disH=INFINITY;
        //     deptoffield = 0;
        //     side = 0;
        //     /* code */
        //     tanges = 1.0/tanges;
        //     if (sin(d2r(cube->v3.rayangle)) > 0.001)
        //     {
        //     printf("tkhrbi9a\n");
        //         cube->v3.rayx = (int)cube->player.y + MINIBLOCK;
        //         cube->v3.rayy = (cube->player.y - cube->v3.rayy) * tanges + cube->player.x ;
        //         cube->v3.yoffset = MINIBLOCK;
        //         cube->v3.xoffset = -cube->v3.yoffset  * tanges;
        //     }
        //     else if(sin(d2r(cube->v3.rayangle)) < -0.001)
        //     {
        //         cube->v3.rayx = (int)cube->player.y - 0.0001;
        //         cube->v3.rayy = (cube->player.y - cube->v3.rayy) * tanges + cube->player.x ;
        //         cube->v3.yoffset = -MINIBLOCK;
        //         cube->v3.xoffset = -cube->v3.yoffset  * tanges;
        //     }
        //     else
        //     {
        //         cube->v3.rayx = cube->player.x;
        //         cube->v3.rayy = cube->player.y;
        //         deptoffield = 8;

        //     }
        //     while (deptoffield < 8)
        //     {
        //         mx =  (int)cube->v3.rayx / MINIBLOCK;
        //         my =  (int)cube->v3.rayy / MINIBLOCK;
        //         // mp = my * WIDTH/MINIBLOCK + mx;
        //         if (cube->map[my][mx]== '1')
        //         {
        //             deptoffield = 8;
        //         }
        //         else
        //         {
        //        cube->v3.rayx += cube->v3.xoffset;
        //        cube->v3.rayy += cube->v3.yoffset;
        //         deptoffield ++;
        //         }
        //     }
        //     i++;
        // }
        //         while (i < 1)
        // {
        //     deptoffield = 0;
        //     /* code */
        //     tanges = 1 / tan(cube->v3.angle);
        //     if (cos(d2r(cube->v3.angle))> 0.001)
        //     {
        //         cube->v3.rayx = roundf(cube->player.x);
        //         /* code */
        //     }
            
        //     i++;
        // // }
        //         cube->dda.endx = cube->v3.rayx ;
        // cube->dda.endy = cube->v3.rayy ;
        