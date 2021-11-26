call plug#begin()

"Themes
Plug 'morhetz/gruvbox'
Plug 'vim-airline/vim-airline-themes'
Plug 'octol/vim-cpp-enhanced-highlight'

"Usefull
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'vim-airline/vim-airline'
Plug 'scrooloose/nerdtree'
Plug 'junegunn/fzf'


call plug#end()

"Appereance
set number
syntax on
colorscheme gruvbox
let g:airline_theme='gruvbox'
let g:gruvbox_termcolors = 256
hi Normal guibg=NONE ctermbg=NONE

"Set
set noswapfile
set incsearch
set hlsearch
set scrolloff=16

"Tab
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
retab

"Keymap
nnoremap <C-n> :NERDTree <CR>



