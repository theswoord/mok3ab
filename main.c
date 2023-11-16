#include "cube3d.h"

// void animation_init(t_cube *cube) // for bonus
// {
//     cube->anim[0] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png"));
//     cube->anim[1] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./dry.png"));

// }

// void *animations_draw(t_cube *cube) // an7yedhom 
// {
//     int i = 0;
//     while (1)
//     {
//         /* code */
//         if (i == 600)
//         {
//             printf("%d\n",i);
//             mlx_image_to_window(cube->window->mlx,cube->anim[0],500,500);
//             // mlx_delete_image(cube->window->mlx,cube->anim[0]);

//             mlx_image_to_window(cube->window->mlx,cube->anim[1],500,500);
//             // cube->anim[0] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png"));
//             // cube->anim[1] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./dry.png"));

//     //         /* code */
//         }
//         // sleep(1);
//             // mlx_image_to_window(cube->window->mlx,cube->anim[1],500,500);
        

//         if(i == 1800)
//             i=0;
//         i++;
//     }
//     return NULL;
// }


void init_mlx(t_cube *cube)
{
    cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    cube->mini_map = mlx_new_image(cube->window->mlx,WIDTH,HEIGHT);
        mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0); // put img ptr on the window
    // mlx_image_to_window(cube->window->mlx, cube->mini_map,50,50);
    mlx_image_to_window(cube->window->mlx, cube->mini_map,0,0);
    // cube->mini_map = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png")); // test image fo9 image hh
}

void draw_background(mlx_image_t *img, t_cube *cube)
{
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);

    // img = mlx_new_image(mlx,WIDTH,HEIGHT);
    // mlx_image_to_window(mlx,)
    // mlx_pn

    // hh = mlx_load_png("./blood.png");
    // hhhh = mlx_texture_to_image(mlx, hh);
    int x = 0;
    int y = 0;
    // printf("%d,%d,%d\n",cube->colors.F[0],cube->colors.F[1],cube->colors.F[2]);
    // printf("%d,%d,%d\n",cube->colors.C[0],cube->colors.C[1],cube->colors.C[2]);

    unsigned long floor = (cube->colors.F[0] << 24) | (cube->colors.F[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;
    unsigned long s9ef = (cube->colors.C[0] << 24) | (cube->colors.C[1] << 16) | (cube->colors.C[2] << 8) | 0xFF; // hadi parsing dial color;

    printf("l3rd %d , lines %d \n",WIDTH,HEIGHT);
    while (x < WIDTH)
    {
        while (y < HEIGHT/2)
        {
        // printf("%d %d\n",x,y);
            mlx_put_pixel(img, x, y, s9ef );
            y++;
        }
        while (y < HEIGHT)
        {
            mlx_put_pixel(img,x,y,floor);
            y++;
        }
        
        y=0;
        x++;
    }
    // mlx_
    // hh.
    // hhj =  mlx_new_image(mlx,100,100);
    // mlx_put_string(mlx,"asdkfjlaksfjklas", 90 ,100);
    // // mlx_image_to_window(mlx , hh ,300,300);
    // mlx_image_to_window(mlx , hh,100,100);
    // // mlx_put_pixel()

}
void map_divider(char * textures , char *background , char *map , t_cube *cube)
{
    cube->background = ft_split (background, '\n');
    free(background);
    cube->textures = ft_split (textures, '\n');
    free(textures);

    cube->map = ft_split (map, '\n');
    free(map);


}
void parse(t_cube *cube)
{
    int i = 0;
    while (cube->background[i])
    {
        rgb_parse(cube->background[i],cube);
        i++;
        /* code */
    }
    
}
void set_rgb(char **tab, t_cube *cube, char what)
{
    int i = 0 ;
    while (tab[i])
    {
        /* code */
        if (what == 'F')
        {
        // printf("f S %s\n", tab[i]);
        cube->colors.F[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
        // printf("F %d\n",cube->colors.F[i]);
            /* code */
        }
        if (what == 'C')
        {
        cube->colors.C[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
        // printf("C %d\n",cube->colors.C[i]);
        
            /* code */
        }
        i++;
    }
    
}
void rgb_parse(char * str, t_cube *cube)
{
    // str = ft_strtrim(str, " \t");
    int i = 0;
    // char what ;
    int is_floor = 0;
    int is_ceilling = 0;
    char what;
    char **work = NULL;
    char* tmp = NULL;
    // found_after_space(str,'F');
    if (found_after_space(str,'F') == true){
        tmp = ft_strtrim(str," \tF");
        free(str);
       what = 'F';
    }
    else if (found_after_space(str,'C') == true){
        tmp = ft_strtrim(str," \tC");
        free(str);
        what = 'C';
    }
    // what = 
    work = ft_split(tmp,',');
    free(tmp);
    set_rgb(work,cube,what); // check before set
    free_tableau(work);
    // while (str[i])
    // {
    //     // if (str[i] == '')
    //     // {
    //     //     /* code */
    //     // }
            
    //     i++;
    //     /* code */
    // }
    
}

void read_map(int fd, t_cube *cube)
{

    char *textures = NULL;
    char *background = NULL;
    char *map = NULL;

    char *line = get_next_line(fd);

    while (line)
    {
        // longline
        if (found_after_space(line,'F') || found_after_space(line,'C') )
        {
            background = ft_strjoingnl(background,line);
            free(line);
            /* code */
        }
            else if (found_after_space(line,'N') || found_after_space(line,'S') ||found_after_space(line,'W') ||found_after_space(line,'E'))
        {
            textures = ft_strjoingnl(textures,line);
            free(line);
            /* code */
        }
           else if (found_after_space(line,'1'))
        {
            map = ft_strjoingnl(map,line);
            free(line);
            /* code */
        }
        else
        {
            free (line);
        }
        line = get_next_line(fd);

    }
    map_divider(textures,background,map,cube);
    // return line;
}

int main(int ac, char **av)
{
    t_cube cube;
    // mlx_t *mlx;
    // mlx_image_t *img;

    int fd = open(av[1], O_RDONLY);
    read_map(fd,   &cube );
    // printf("%s\n", cube.background[0]);
    // print_tableau(cube.textures);
    // printf("---------------------\n");
    // print_tableau(cube.map);
    // printf("---------------------\n");

    print_tableau(cube.background);
    parse(&cube);
    init_mlx(&cube);
    fill_map(&cube);
    // printf("%s\n",cube.map[2]);
    print_tableau(cube.map);
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    // img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // printf("fff\n");
    draw_background(cube.window->img, &cube); // made the imgptr
    mini_map_draw(&cube);

    // animation_init(&cube); // memes
    // mlx_loop_hook(cube.window->mlx,animations_draw,&cube);
    // mlx_loop_hook(cube.window->mlx,pressed,&cube);
    mlx_key_hook(cube.window->mlx,&pressed,&cube);
    mlx_loop(cube.window->mlx);
    mlx_terminate(cube.window->mlx);
    return 0;
}