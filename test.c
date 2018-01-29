#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
#define DEPTH 1000     //  чем выше этотпоказатель, тем "глубже" получается картинка
 
unsigned char far *screen = (unsigned char far *) 0xA0000000;
 
//вызываем прерывание 10h
void SetMode (unsigned short mode) {
  asm {
	 mov ax, [mode]
	 int 0x10
  }
}
 
//установка точки на экран
void putpixel (int x, int y, int color)
{
	screen[y * 320 + x] = color;
	return;
}
//функция установки цвета
void setpallette (unsigned char num,unsigned char r,
		  unsigned char g,unsigned char b)
{
   outp (0x3c6,0xff);
   outp (0x3c8,num);
   outp (0x3c9,r);
   outp (0x3c9,g);
   outp (0x3c9,b);
}
int main() {
 
  SetMode(0x13);
 
  float zi, zr, ci, cr, tmp;
  int i, j, k, m;
 
  for(i = -160; i < 160; i++) {                      //  проходим по всем пикселям оси х
 
	 ci = ((float)i) / 160.0;                    //  присваеваем мнимой части с - i/160
	 for(j = -190; j < 10; j++) {                 //  проходим по всем пикселям оси y6
 
		cr = ((float)j) / 120.0;             //  присваеваем вещественной части с - j/120
		zi = zr = 0.0;                       //  присваеваем вещественной и мнимой части z - 0
		for(k = 0; k < DEPTH; k++) {         //  вычисляем множество Мандельброта
 
		  tmp = zr*zr - zi*zi;
		  zi = 2*zr*zi + ci;
		  zr = tmp + cr;
		  if (zr*zr + zi*zi > 1.0E16)        //  если |z| слишком велико, то
		    break;                           //  выход из цикла
		}
		if (k < DEPTH) {                     //  |z| - велико
		  m = k%8 + 1;                       //  - это внешняя точка
		  setpallette(m, m*8 + 7, 0, 0);     //  выбираем оттенок
		  putpixel(i + 160, j + 190, m);     //	 красного
		}
		else
		  putpixel(i + 160, j + 190, 0);      // внутренняя точка и закрашиваем её в чёрный цвет
	 }
	 if(kbhit())                                  // пока не нажата клавиша
	   break;
  }
 
  getch();
  return 0;
}



////////////////


int main(int argc, char *argv[])
{
  screen(400, 300, 0, "Mandelbrot Set"); //make larger to see more detail!

  //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
  double pr, pi;           //real and imaginary part of the pixel p
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
  double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
  ColorRGB color; //the RGB color value for the pixel
  int maxIterations = 300;//after how much iterations the function should stop

  //loop through every pixel
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
    pi = (y - h / 2) / (0.5 * zoom * h) + moveY;
    newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
    //"i" will represent the number of iterations
    int i;
    //start the iteration process
    for(i = 0; i < maxIterations; i++)
    {
      //remember value of previous iteration
      oldRe = newRe;
      oldIm = newIm;
      //the actual iteration, the real and imaginary part are calculated
      newRe = oldRe * oldRe - oldIm * oldIm + pr;
      newIm = 2 * oldRe * oldIm + pi;
      //if the point is outside the circle with radius 2: stop
      if((newRe * newRe + newIm * newIm) > 4) break;
    }
    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
    color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
     //draw the pixel
     pset(x, y, color);
  }
  //make the Mandelbrot Set visible and wait to exit
  redraw();
  sleep();
  return 0;
}



////////////



unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    PaintBox1: TPaintBox;
    procedure Button1Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
type
	TComplex = record
		x : Real;
		y : Real;
	end;

const
	iter = 50;
	max  = 16;

var
	z, t, c : TComplex;
	x, y, n : Integer;
	Cancel  : Boolean;
	gd, gm  : Smallint;
	mx, my  : Integer;
        col:TColor;
begin

   PaintBox1.Canvas.Clear; //очищаем canvas
     Randomize;
     Mx := PaintBox1.Canvas.Width div 2;   //определяем центр canvas'a по ширине
     My := PaintBox1.Canvas.Height div 2;  //определяем центр canvas'a по высоте
     	for y := -my to my do   //идем по canvas'у с помощью двойного цикла
  		for x := -mx to mx do
  		begin
                         //устанавливаем   значения параметров
  			n := 0;
  			c.x := x * 0.005;
  			c.y := y * 0.005;
  			z.x := 0;
  			z.y := 0;
  			while (sqr(z.x) + sqr(z.y) < max) and (n < iter) do
  			begin
  				t := z;
  				z.x := sqr(t.x) - sqr(t.y) + c.x;
  				z.y := 2 * t.x * t.y+ c.y;
  				Inc(n);

  			end;
               //цвет выбирается по числу итераций
  		if n < iter then
  		begin
                              col := n*6 mod 255; // находим цвет
              //перекрашиваем соответствующую точку на canvas'e в соответствующий цвет
                          PaintBox1.Canvas.Pixels[mx+x,my+y]:=RGBToColor(0,col,0);
  		end;
  	end;
end;

end.
