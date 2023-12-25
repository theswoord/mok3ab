#include "cube3d.h"



unsigned long *extract_color(mlx_texture_t *texture)
{
    int i = 0;
    int j = 0;
    int total = texture->height * texture->width * texture->bytes_per_pixel;
    unsigned long *tmp = NULL;
    tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
    // printf("%lu \n", malloc_good_size(tmp));
    // printf("hh\n");
    while (i < total)
    {
        // j++;
        // if (/* condition */)
        // {
        //     /* code */
        // }

        tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j + 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j + 3]);
        j += texture->bytes_per_pixel;
        // printf("%d\n", j);
        i++;
    }
    // mlx_delete_texture(texture);
    return (tmp);
}

int main()
{

    
    mlx_t *mlx;
    mlx_image_t * test;


    mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);

    test =  mlx_new_image(mlx, WIDTH, HEIGHT);
    mlx_image_to_window(mlx,test,0,0); 


    unsigned long *te = NULL;
    mlx_texture_t * hh = mlx_load_png("./textures/SO.png");
    te = extract_color(hh);
    
    // for (size_t i = 0; i < 1024; i++)
    // {
    //     mlx_put_pixel(test,50,50,te[i]);
    // }
    
    // for (size_t i = 0; i < (hh->bytes_per_pixel * hh->height * hh->width); i++)
    // {
    //     printf("%d ", hh->pixels[i]);
    //     if (i %3 == 0)
    //     {
    //     printf("\n");

    //         /* code */
    //     }
        
    // }
    





    mlx_loop(mlx);
}