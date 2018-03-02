"""
Control GUI

@author: elie
"""

import tkinter as tk
import logging

import numpy as np

import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation

# plot
f = Figure(figsize=(6,4), dpi=100)
a1 = f.add_subplot(311)
a2 = f.add_subplot(312,sharex=a1)
a3 = f.add_subplot(313,sharex=a1)
data = np.zeros([0,17])

is_anim_paused = False

def animate(i):
    if is_anim_paused:
        pass
    else:
        a1.clear()
        a2.clear()
        a3.clear()
        a1.plot(data[:,2], data[:,3])
        a1.plot(data[:,2], data[:,10])
        a2.plot(data[:,2], data[:,4])
        a2.plot(data[:,2], data[:,11])
        a3.plot(data[:,2], data[:,5])
        a3.plot(data[:,2], data[:,12])

def start_anim():
    global ani
    ani = animation.FuncAnimation(f, animate, interval=100)

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.toggle_motors = False
        self.toggle_control = False
        self.toggle_recording = False
        self.should_quit = False
        
        self.create_widgets()
        start_anim()

    def create_widgets(self):
        # create buttons
        self.fr_buttons = tk.Frame()
        self.fr_buttons.pack()
        
        self.bt_switch_motors = tk.Button(self.fr_buttons)
        self.bt_switch_motors["text"] = "Motors On/Off"
        self.bt_switch_motors["command"] = self.motors_switch
        
        self.bt_switch_control = tk.Button(self.fr_buttons)
        self.bt_switch_control["text"] = "Control On/Off"
        self.bt_switch_control["command"] = self.control_switch
        
        self.bt_switch_recording = tk.Button(self.fr_buttons)
        self.bt_switch_recording["text"] = "REC"
        self.bt_switch_recording["command"] = self.recording_switch
        
        self.bt_switch_anim = tk.Button(self)
        self.bt_switch_anim["text"] = "Pause"
        self.bt_switch_anim["command"] = self.pause_switch

        self.bt_quit = tk.Button(self, text="QUIT", fg="red", command=self.clean_quit)
        
        # create ref sliders
        self.sc_ref_x = tk.Scale(self.fr_buttons, from_=-2, to=2, resolution=0.01, length=200, label='X', orient=tk.HORIZONTAL)
        self.sc_ref_y = tk.Scale(self.fr_buttons, from_=-2, to=2, resolution=0.01, length=200, label='Y', orient=tk.HORIZONTAL)
        self.sc_ref_z = tk.Scale(self.fr_buttons, from_=-2, to=0, resolution=0.01, length=200, label='Z', orient=tk.HORIZONTAL)
        self.sc_ref_psi = tk.Scale(self.fr_buttons, from_=-180, to=180, length=200, label='Psi', orient=tk.HORIZONTAL)
        
        # create gains sliders
        self.sc_gain_kpxy = tk.Scale(self.fr_buttons, from_=0, to=2, resolution=0.01, length=200, label='Kpxy', orient=tk.HORIZONTAL)
        self.sc_gain_kpz = tk.Scale(self.fr_buttons, from_=0, to=2, resolution=0.01, length=200, label='Kpz', orient=tk.HORIZONTAL)
        self.sc_gain_kdxy = tk.Scale(self.fr_buttons, from_=0, to=2, resolution=0.01, length=200, label='Kdxy', orient=tk.HORIZONTAL)
        self.sc_gain_kdz = tk.Scale(self.fr_buttons, from_=0, to=2, resolution=0.01, length=200, label='Kdz', orient=tk.HORIZONTAL)
        
        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        
        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        
        # place widgets
        self.bt_switch_motors.grid(row=0, column=0)
        self.bt_switch_control.grid(row=0, column=1)
        self.bt_switch_recording.grid(row=0, column=2)
        
        self.sc_gain_kpxy.grid(row=1, column=0)
        self.sc_gain_kpz.grid(row=2, column=0)
        self.sc_gain_kdxy.grid(row=3, column=0)
        self.sc_gain_kdz.grid(row=4, column=0)
        
        self.sc_ref_x.grid(row=1, column=1, columnspan=2)
        self.sc_ref_y.grid(row=2, column=1, columnspan=2)
        self.sc_ref_z.grid(row=3, column=1, columnspan=2)
        self.sc_ref_psi.grid(row=4, column=1, columnspan=2)
        
        canvas.get_tk_widget().pack(side=tk.BOTTOM,fill=tk.BOTH, expand=1)
        canvas._tkcanvas.pack(side=tk.BOTTOM,fill=tk.BOTH, expand=1)
        
        self.bt_switch_anim.pack()
        self.bt_quit.pack(side=tk.BOTTOM)
    
    def motors_switch(self):
        self.toggle_motors = True
    
    def control_switch(self):
        self.toggle_control = True
        
    def recording_switch(self):
        self.toggle_recording = True
        if self.bt_switch_recording['bg']=="red":
            self.bt_switch_recording['bg']="white"
        else:
            self.bt_switch_recording['bg']="red"
    
    def pause_switch(self):
        global is_anim_paused
        is_anim_paused = not is_anim_paused
    
    def clean_quit(self):
        self.should_quit = True
    
    def set_ref_sliders(self, values):
        x, y, z, psi = values
        self.sc_ref_x.set(x)
        self.sc_ref_y.set(y)
        self.sc_ref_z.set(z)
        self.sc_ref_psi.set(psi)
        
    def get_ref_sliders(self):
        x = self.sc_ref_x.get()
        y = self.sc_ref_y.get()
        z = self.sc_ref_z.get()
        psi = self.sc_ref_psi.get()
        return (x, y, z, psi)
        
    def set_gain_sliders(self, values):
        kpxy, kpz, kdxy, kdz = values
        self.sc_gain_kpxy.set(kpxy)
        self.sc_gain_kpz.set(kpz)
        self.sc_gain_kdxy.set(kdxy)
        self.sc_gain_kdz.set(kdz)
        
    def get_gain_sliders(self):
        kpxy = self.sc_gain_kpxy.get()
        kpz = self.sc_gain_kpz.get()
        kdxy = self.sc_gain_kdxy.get()
        kdz = self.sc_gain_kdz.get()
        return (kpxy, kpz, kdxy, kdz)