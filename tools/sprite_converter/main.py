# Very lazy script to auto convert the oneko xbms to xpms while keeping the alpha

from PIL import Image, ImageOps
import os
import pathlib
import xpm

name_table = {
	"awake": "awake",
    "down1": "down",
    "down2": "down_alt",
    "dtogi1": "bottom",
    "dtogi2": "bottom_alt",
    "dwleft1": "down_left",
    "dwleft2": "down_left_alt",
    "dwright1": "down_right",
    "dwright2": "down_right_alt",
    "jare2": "lick",
    "kaki1": "scratch",
    "kaki2": "scratch_alt",
    "left1": "left",
    "left2": "left_alt",
    "ltogi1": "side_l",
    "ltogi2": "side_l_alt",
    "mati2": "idle",
    "mati3": "yawn",
    "right1": "right",
    "right2": "right_alt",
    "rtogi1": "side_r",
    "rtogi2": "side_r_alt",
    "sleep1": "sleep",
    "sleep2": "sleep_alt",
    "up1": "up",
    "up2": "up_alt",
    "upleft1": "up_left",
    "upleft2": "up_left_alt",
    "upright1": "up_right",
    "upright2": "up_right_alt",
    "utogi1": "top",
    "utogi2": "top_alt"
}
name = "bsd"
mask_name = "bsd"
map_dir = pathlib.Path("/home/wolfie/Downloads/onekoC/bitmaps")
mask_dir = pathlib.Path("/home/wolfie/Downloads/onekoC/bitmasks")
xpm_dir = pathlib.Path(f"{name}_xpm")

if not os.path.exists(name):
    os.mkdir(name)
if not os.path.exists(xpm_dir):
    os.mkdir(xpm_dir)

sprite_dir = pathlib.Path(f"{map_dir}/{name}")
mask_dir = pathlib.Path(f"{mask_dir}/{mask_name}")
for file in os.listdir(sprite_dir):
    filename, ext = os.path.splitext(file)
    if (ext == ".xbm"):
        image = Image.open(pathlib.Path(str(sprite_dir) + "/" + file))
        mask = Image.open(pathlib.Path(str(mask_dir) + "/" + filename + "_mask.xbm"))
        inverted_image = ImageOps.invert(image)
        rgba_image = inverted_image.convert("RGBA")
        rgba_image.putalpha(mask)
        rgba_image.save(f"{name}/{name_table[filename.split('_')[0]]}.png")
        xpm_string = xpm.pil_save(rgba_image, variable_name=name_table[filename.split('_')[0]].encode("utf-8"))
        with open(pathlib.Path(f"{xpm_dir}/{name_table[filename.split('_')[0]]}.xpm"), "w") as f:
            f.write(xpm_string.decode("utf-8"))
        print(name_table[filename.split("_")[0]])
