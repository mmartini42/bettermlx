<h1 align="center">
	bettermlx
</h1>

<h2>
	Sommaire
</h2>

- # Fonctions

- Initialisation de la window<br>
<a href="#Init_window"><code>t_window *bettermlx_init_window(char *title, int width, int height, int divider);</code></a>
- Destruction de la window<br>
<a href="#Destroy_window"><code>void *bettermlx_destroy_window(t_window **window);</code></a>
- Initialisation de l'image<br>
-<a href="#Init_img"><code>t_image	*bettermlx_init_xpm_image(t_window *window, char *path);</code></a>
- Destruction de l'image<br>
<a href="#Destroy_img"><code>void *bettermlx_destroy_image(t_window *window, t_image **image);</code></a>
- Init Image .xmp<br>
<a href="#Xmp_img"><code>t_image *bettermlx_init_xpm_image(t_window *window, char *path);</code></a>
- Recupere la position d'un pixel dans la memoire<br>
<a href="Mem_position"><code>unsigned char *bettermlx_get_memory_position(t_image *image, int x, int y);</code></a>
- Recupere la couleur d'un pixel<br>
<a href="#Img_color"><code>t_color bettermlx_get_color(t_image *image, int x, int y);</code></a>
- Met la couleur d'un pixel <br>
<a href="#Set_pixel"><code>void bettermlx_pixel_put(t_window *window, t_vector3 pixel_coordinates, t_color color, float darkness);</code></a>

- Affiche une ligne<br>
<a href="#draw_line"><code>void bettermlx_draw_line(t_window *window, t_vector3 xy1, t_vector3 xy2, t_color color);</code></a>
- Netoie la fenetre<br>
<a href="#clean_display"><code>void bettermlx_clean_display(t_window *window);</code></a>
- Fait un rendu de la window<br>
<a href="#Render"><code>void	bettermlx_render(t_window *window);</code></a>
- Enregistre un nouveau hook<br>
<a href="#hook"><code>void	bettermlx_hook(t_window *window, t_x11event x11event, int (*funct)(), void *param);</code></a>
- Execute une boucle<br>
<a href="#loop_hook"><code>void	bettermlx_register_loop(t_window *window, void *param, int (*funct_ptr)());</code></a>
- Recupere le temps<br>
<a href="#Time"><code>long long	bettermlx_get_time(void);</code></a>
- # Structures

- <a href="#Struct_window"><code>t_window</code></a>
- <a href="#Struct_img"><code>t_image</code></a>
- <a href="#Struct_color"><code>t_color</code></a>
- <a href="#Struc_vector"><code>s_vector3</code></a>

- # Enum
- <a href="#Enum_X11"><code>t_x11event</code></a>

<div id="Struct_window"></div>

# #Structure t_window

```
typedef struct s_window
{
	char	*title;
	int		width;
	int		height;
	int		real_width;
	int		real_height;
	int		divider;
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
	t_bool	keyboard[384];
}			t_window;
```

<h4 id="Init_window">
# Initialisation de la window
</h4>

```t_window	*bettermlx_init_window(char *title, int width, int height, int divider);```


<h5>La fonction fait:</h5>

- Une allocation de la structure avec <code>ft_calloc()</code><br>
- Set les valeurs dans la structure<br>
- Init un pointeur mlx avec [<code>mlx_init()</code>](./Mlx/mlx_init)<br>
- Cree une window avec [<code>mlx_new_window()</code>](./Mlx/mlx_new_window)<br>
- Init une image avec <a href="#init_img"><code>bettermlx_init_image()</code></a><br>
- Empêche la répétition de touche avec [<code>mlx_do_key_autorepeatoff()</code>](./Mlx/mlx_do_key_autorepeatoff)<br>
<b><i>Retourne un<code>t_windod*</code><i></b>
<h6>Utilisation</h6>

```
	t_window	*window;

	window = bettermlx_init_window("Mon titre", 1920, 1080, 1);
	//code
```

<h4 id="Destroy_window">
# Destruction de la window
</h4>

```void			*bettermlx_destroy_window(t_window **window);```
<h5>La fonction fait:</h5>

- Une destruction de l'image avec <a href="#Destroy_img"><code>bettermlx_destroy_image()</code></a><br>
- Une destruction de la window avec [<code>mlx_destroy_window()</code>](./Mlx/mlx_destroy_window)<br>
- Une destruction du pointeur mlx avec [<code>mlx_destroy_mlx()</code>](./Mlx/mlx_destroy_mlx)<br>
- Un <code>free()</code> du pointeur sur la strucure<br>
<b><i>Retourne <code>NULL</code><i></b>

<h6>Utilisation</h6>

```
	t_window	*window;

	window = bettermlx_init_window("Mon titre", 1920, 1080, 1);
	//code
	bettermlx_destroy_window(&window);
```

<div id="Struct_img"></div>
# #Structure t_image

```
typedef struct s_image
{
	int			width;
	int			height;
	void		*img_ptr;
	char		*img_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}
```

<h4 id="Init_img">
# Initialisation de l'image
</h4>

```t_image	*bettermlx_init_image(t_window *window, int width, int height);```

<h5>La fonction fait:</h5>

- Une allocation de la structure avec <code>ft_calloc</code><br>
- Set les valeurs dans la structure<br>
- Set img_ptr à l'aide de la fonction [<code>mlx_new_image()</code>](./Mlx/mlx_new_image)<br>
- Donne les informations à img_data avec [<code>mlx_get_data_addr()</code>](./Mlx/mlx_get_data_addr)<br>
<b><i>Retourne un<code>t_image*</code><i></b>

<h6>Utilisation</h6>

```
	t_window	*window;
	t_image		*image;

	window = bettermlx_init_window("Mon titre", 1000, 500, 1);
	image = bettermlx_init_image(window, 1920, 1080);
	//code
```

<h4 id="Destroy_img">
# Destruction de l'image
</h4>

```void *bettermlx_destroy_image(t_window *window, t_image **image);```

<h5>La fonction fait:</h5>

- Une destruction de l'image avec [<code>mlx_destroy_image()</code>](./Mlx/mlx_destroy_image);
- Un <code>free()</code> du pointeur sur la structure <code>t_image</code>
- Met a <code>NULL</code> le pointeur sur la structure<br>
<b><i>Retourne <code>NULL</code><i></b>

<h6>Utilisation</h6>

```
	t_window	*window;
	t_image		*image;

	window = bettermlx_init_window("Mon titre", 1000, 500, 1);
	image = bettermlx_init_image(window, 1920, 1080);
	//code
	bettermlx_destroy_image(window, &image);
```

<h4 id="Put_img">
# Affichage d'une image
</h4>

```void	bettermlx_put_image(t_window *window, t_image *image, int x, int y);```

<h5>La fonction fait:</h5>

- Un appel a la fonction <a href="#Set_pixel"><code>bettermlx_pixel_put()</code></a> en recuperant toutes les information depuis une image xpm

<h4 id="Xmp_img">
# Initialisation d'une image dans la window en fonction d'un fichier .xmp
</h4>

```t_image	*bettermlx_init_xpm_image(t_window *window, char *path);```

<h5>La fonction fait:</h5>

- Une allocation de la structure avec <code>ft_calloc()</code><br>
- Donne les informations de l'image à img_ptr avec [<code>mlx_xpm_file_to_image()</code>](./Mlx/mlx_xpm_file_to_image)
- Donne les informations à img_data avec [<code>mlx_get_data_addr()</code>](./Mlx/mlx_get_data_addr)<br>
<b><i>Retourne un<code>t_image*</code><i></b>

<h4 id="Mem_position">
# Recupere la position d'un pixel dans la memoire
</h4>

```unsigned char *bettermlx_get_memory_position(t_image *image, int x, int y);```

<h5>La fonction fait:</h5>

- Une verification si le pixel est dans la limite de l'image<br>
<b><i>Retourne la position</code><i></b>

<div id="Struct_color"></div>

# #Structure t_color

```
typedef struct s_color
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;
```

<h4 id="Img_color">
# Recupere la couleur d'un pixel
</h4>

```t_color bettermlx_get_color(t_image *image, int x, int y);```

<h5>La fonction:</h5>

- Recupere la position du pixel avec <a href="#Mem_position"><code>bettermlx_get_memory_position()</code></a>
- Si la position n'est pas valide la couleur renvoye sera du noire<br>
- La couleur est obtenue par [<code>create_color()</code>](./Annex/create_color)<br>
<b><i>Retourne la couleur<i></b>


<div id="Struc_vector"></div>

# #Structure t_vector3

```
typedef struct s_vector3
{
	float	vx;
	float	vy;
	float	vz;
}	t_vector3;
```

<h4 id="Set_color">
# Met la couleur d'un pixel
</h4>

```void	bettermlx_set_color(t_image *image, t_vector3 pixel_coordinates, t_color color, float darkness);```

<h5>La fonction:</h5>

- Recupere la position du pixel avec <a href="#Mem_position"><code>bettermlx_get_memory_position()</code></a>
- Set les valeurs definie dans t_color aux position t_vector3


<h4 id="Set_pixel">
# Affiche un pixel
</h4>

```void bettermlx_pixel_put(t_window *window, t_vector3 pixel_coordinates, t_color color, float darkness);```

<h5>La fonction:</h5>

- Convertie les coordonne en fonction du divider (Scale)<code>s_window::divider</code>
- Met la couleur du pixel avec <a href="#Set_color"><code>bettermlx_set_color()</code></a>
- <code>bettermlx_set_color(window->image, </code>[<code>create_vector</code>](./Annex/create_vector)<code>(ax, ay, 0),color, darkness);</code>


<h4 id="draw_line">
# Affiche une ligne
</h4>

```void bettermlx_draw_line(t_window *window, t_vector3 xy1, t_vector3 xy2, t_color color);```

<h5>La fonction:</h5>

- Recupere la dérive (la pente)
- Crée un vector avec les nouvelles coordonne [<code>create_vector</code>](./Annex/create_vector)<br>
- Utilise la fonction <a href="#Set_pixel"><code>bettermlx_pixel_put()</code></a> Pour afficher la ligne

<h4 id="clean_display">
#Netoie la fenetre
</h4>

```void bettermlx_clean_display(t_window *window);```

<h5>La fonction:</h5>

- Recupere la couleur de fond (noir) avec [<code>create_color()</code>](./Annex/create_color)
- Affiche les pixel avec <a href="#Set_pixel"><code>bettermlx_pixel_put()</code></a>

<h4 id="Render">
#Fait un rendu de la window
</h4>

```void	bettermlx_render(t_window *window);```

<h5>La fonction:</h5>

- Execute la fonction [<code>mlx_put_image_to_window()</code>](./Mlx/mlx_put_image_to_window)

<div id="Enum_X11"></div>
# #Enum t_x11event

```
typedef enum e_x11event
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELESE = 5,
	MOTION_NOTIFY = 6,
	ENTER_NOTIFY = 7,
	LEAVE_NOTIFY = 8,
	FOCUS_IN = 9,
	FOCUS_OUT = 10,
	KEYMAP_NOTIFY = 11,
	EXPOSE = 12,
	GRAPHICS_EXPOSE = 13,
	NO_EXPOSE = 14,
	VISIBILITY_NOTIFY = 15,
	CREATE_NOTIFY = 16,
	DESTROY_NOTIFY = 17,
	UNMAP_NOTIFY = 18,
	MAP_NOTIFY = 19,
	MAP_REQUEST = 20,
	REPARENT_NOTIFY = 21,
	CONFIGURE_NOTIFY = 22,
	CONFIGURE_REQUEST = 23,
	GRAVITY_NOTIFY = 24,
	RESIZE_REQUEST = 25,
	CIRCULATE_NOTIFY = 26,
	CIRCULATE_REQUEST = 27,
	PROPERTY_NOTIFY = 28,
	SELECTION_CLEAR = 29,
	SELECTION_REQUEST = 30,
	SELECTION_NOTIFY = 31,
	COLORMAP_NOTIFY = 32,
	CLIENT_MESSAGE = 33,
	MAPPING_NOTIFY = 34,
	GENERIC_EVENT = 35,
	LAST_EVENT = 36,
}				t_x11event;
```

<h4 id="hook">
#Enregistre un nouveau hook
</h4>

```void	bettermlx_hook(t_window *window, t_x11event x11event, int (*funct)(), void *param);```

<h5>La fonction:</h5>

- Appel la fonction [<code>mlx_hook()</code>](./Mlx/mlx_hook)


<h4 id="loop_hook">
#Execute une boucle
</h4>

```void	bettermlx_register_loop(t_window *window, void *param, int (*funct_ptr)());```

<h5>La fonction:</h5>

- Execute la fonction [<code>mlx_loop_hook()</code>](./Mlx/mlx_loop_hook)
- Execute la fonction [<code>mlx_loop()</code>](./Mlx/mlx_loop)

<h4 id="Time">
#Recupere le temps
</h4>

```long long	bettermlx_get_time(void);```

<h5>La fonction:</h5>

- Recupere l'heure avec la fonction() ```gettimeofday```<br>
<b><i>Retourne l'heure en milliseconds<i></b>
