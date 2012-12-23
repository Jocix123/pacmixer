// This is a part of pacmixer @ http://github.com/KenjiTakahashi/pacmixer
// Karol "Kenji Takahashi" Woźniak © 2012
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#import "options.h"


@implementation Options
-(Options*) initWithOptions: (NSArray*) options_
                  andParent: (WINDOW*) parent {
    self = [super init];
    options = options_;
    highlight = 0;
    int my = getmaxy(parent);
    int dy = [options count];
    win = derwin(parent, dy + 2, 8, my - dy - 3, 0);
    box(win, 0, 0);
    [self print];
    return self;
}

-(void) dealloc {
    delwin(win);
    [super dealloc];
}

-(void) print {
    int dy = [options count];
    for(int i = 0; i < dy; ++i) {
        NSString *obj = [options objectAtIndex: i];
        if(i == highlight) {
            wattron(win, COLOR_PAIR(6));
        }
        mvwprintw(win, i + 1, 1, "      ");
        mvwprintw(win, i + 1, 1, "%@", obj);
        wattroff(win, COLOR_PAIR(6));
    }
}

-(void) show {
    [self print];
}

-(void) setCurrent: (int) i {
    highlight = i;
    [self print];
}

-(void) up {
    if(highlight > 0) {
        [self setCurrent: highlight - 1];
    }
}

-(void) down {
    if(highlight < [options count] - 1) {
        [self setCurrent: highlight + 1];
    }
}
@end