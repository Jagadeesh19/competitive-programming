source $VIMRUNTIME/vimrc_example.vim

set hls
set is
set cb=unnamedplus
set gfn=Fixedsys:h10
set ts=4
set sw=4
set si
set ai

ab #c /*<CR>*/<esc>O
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

set nu

nnoremap <F7> :!clear<CR>
autocmd filetype cpp nnoremap  <F8> :w <bar> !g++ -std=c++14 -g  % -o %:r<CR>
autocmd filetype cpp nnoremap  <F9> :!./%:r<CR>
autocmd filetype python nnoremap  <F9> :!python %:r.py<CR>
autocmd filetype javascript  nnoremap  <F9> :!node %:r.js<CR>


augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction
