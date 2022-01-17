syntax on
let mapleader =" "
set encoding=utf-8
set nocompatible
filetype plugin on
set list

" Easy Split Navigation
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

" Indentation
set tabstop=2 softtabstop=0 shiftwidth=2 smarttab expandtab

" Searching
set smartcase

" Backups
set noswapfile
set nobackup
set undodir=~/.config/nvim/undodir
set undofile

" Right column at 80 lines for good coding practice.
set colorcolumn=80

" QoL
set showmatch " Show matching Brackets
set number relativenumber " Side numbers

" Fuzzy finding by allowing searching into subfolders
set path+=**
set wildmenu
" use :find to find, and * to make it fuzzy.
" Also make use of :b.

" Delete trailing white space and newlines at end of file on save.
autocmd BufWritePre * %s/\s\+$//e
autocmd BufWritePre * %s/\n\+\%$//e

" Easy copy and pasting to external programs
map <C-y> "+yy
map <C-p> "+P

call plug#begin("~/.config/nvim/plugged")

" Functionality
Plug 'neoclide/coc.nvim' " Auto completion
Plug 'mcchrish/nnn.vim' " nnn in vim
Plug 'tpope/vim-commentary' " Comment out (multi-)lines
Plug 'tpope/vim-fugitive' " Git Plugin
Plug 'lervag/vimtex' " Latex support
Plug 'tmhedberg/SimpylFold' " Good python folding

" Look & Feel
Plug 'catppuccin/nvim' " Color Scheme
Plug 'bling/vim-airline' " Status Bar
Plug 'sheerun/vim-polyglot' " Syntax Highlighting
Plug 'luochen1990/rainbow' " Rainbow Paranthesis
Plug 'ap/vim-css-color' " Preview colors

call plug#end()

" Colorscheme

colorscheme catppuccin

" nnn settings
let g:nnn#layout = { 'window': { 'width': 0.35, 'height': 0.5, 'xoffset': 1.0, 'highlight': 'Debug' } } " hover window
" let g:nnn#layout = 'vnew' " Verticle Split
let g:nnn#action = {
    \ '<c-t>': 'tab split',
    \ '<c-v>': 'vsplit' }
let g:nnn#command = 'nnn -HeT v'
let g:nnn#replace_netrw = 1

" Remove \"-- INSERT --\" indicator from statusbar
set noshowmode

" Toggle Color Highlights
command! ColorToggle call css_color#toggle()

" Rainbow Paranthesis
let g:rainbow_actve = 1

autocmd BufRead,BufNewFile *.md call WritingMode()
autocmd BufRead,BufNewFile *.py call PythonMode()

function! WritingMode()
  setlocal textwidth=80
  setlocal wrap linebreak nolist
  setlocal whichwrap+=<,>,h,l
  nnoremap j gj
  nnoremap k gk
  setlocal spell spelllang=en_us
endfunction
function! PythonMode()
  setlocal foldmethod=indent
  setlocal foldlevel=99
endfunction
