#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song{
	char title[30], artist[20], dur[10];
	song *prev, *next;
}*head = NULL, *tail = NULL;

song* create(char title[], char artist[], char dur[]){
	song* node = (song*)malloc(sizeof(song));
	strcpy(node->title, title);
	strcpy(node->artist, artist);
	strcpy(node->dur, dur);
	node->prev = node->next = NULL;
	return node;
}

void insertSong(char title[], char artist[], char dur[]){
	song* node = create(title, artist, dur);
	if(!head) head = tail = node;
	else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void insertAfter(char after[], char title[], char artist[], char dur[]){
	song* node = create(title, artist, dur);
	song* curr = head;
	while(curr && strcmp(curr->title, after) != 0) curr = curr->next;
	curr = curr->next;
	node->next = curr;
	node->prev = curr->prev;
	curr->prev->next = node;
	curr->prev = node;
	printf("'%s' inserted after '%s'.\n", node->title, node->prev->title);
	
}

void insertBefore(char before[], char title[], char artist[], char dur[]){
	song* node = create(title, artist, dur);
	song* curr = head;
	while(curr->next && strcmp(curr->next->title, before) != 0) curr = curr->next;
	curr = curr->next;
	node->next = curr;
	node->prev = curr->prev;
	curr->prev->next = node;
	curr->prev = node;
	printf("'%s' inserted before '%s'.\n", node->title, node->next->title);
	
}


void popHead(){
	if(!head) head = tail = NULL;
	else{
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			song* del = head;
			head = head->next;
			head->prev = NULL;
			free(del);
		}
	}
}

void popTail(){
	if(!head) head = tail = NULL;
	else{
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			song* del = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(del);
		}
	}
}

void clearPlaylist(){
	while(head) popHead();
	puts("Playlist cleared.");
}

void showPlaylist(){
	if(!head){
		puts("Playlist is empty.");
		return;
	}
	song* curr = head;
	puts("Playlist:");
	while(curr){
		printf("Title: %s | Artist: %s | Duration: %s\n", curr->title, curr->artist, curr->dur);
		curr = curr->next;
	}
	
}

void removeSong(char title[]){
	if(!head) return;
	else if(strcmp(title, head->title) == 0){
		printf("Song '%s' removed from the playlist.\n", head->title);
		popHead();
	}
	else if(strcmp(title, tail->title) == 0){
		printf("Song '%s' removed from the playlist.\n", tail->title);
		popTail();
	}
	else{
		song* curr = head;
		while(curr->next && strcmp(curr->next->title, title) != 0) curr = curr->next;
		if(!curr->next) return;
		song* del = curr->next;
		printf("Song '%s' removed from the playlist.\n", del->title);
		curr->next = del->next;
		del->next->prev = curr;
		del = NULL;
		free(del);
	}
}
int main(){
	insertSong("Song Title 1", "Artist 1", "03:30");
	insertSong("Song Title 2", "Artist 2", "04:15");
	insertSong("Song Title 3", "Artist 3", "02:50");
	insertSong("Song Title 4", "Artist 4", "05:00");
	
	showPlaylist();
	insertAfter("Song Title 2", "Song Title 2.5", "Artist 2.5", "01:45");
	insertBefore("Song Title 4", "Song Title 3.5", "Artist 3.5", "02:30");
	
	showPlaylist();
	removeSong("Song Title 2.5");
	removeSong("Song Title 4");
	
	showPlaylist();
	clearPlaylist();
	showPlaylist();
}
