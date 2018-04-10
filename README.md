# Coplien Form creator C++
Creates files .cpp .hpp in necessary places with all needed inclusions.

## Installation

```bash
mkdir ~/.software
cd ~/.software
git clone https://github.com/andreyfaraponov/Coplien-Form-creator-C-plus-plus
make -C Coplien-Form-creator-C-plus-plus
echo "alias coplien='~/.software/Coplien-Form-creator-C-plus-plus/ft_coplien'" >> ~/.bashrc
or
echo "alias coplien='~/.software/Coplien-Form-creator-C-plus-plus/ft_coplien'" >> ~/.zshrc
```
## Useage flags

Option | Description
------ | -----------
-l | disable including includes and srcs folders
-algo | includes <algorithm>
  -ios | includes <iostream>
  -fs | includes <fstream>
  -vector | includes <vector>
  -all | includes all above without -l
