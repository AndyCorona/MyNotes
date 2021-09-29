package com.likezhen.springdemo.chapter2.XmlConfig;

import com.likezhen.springdemo.chapter2.Autowired.CD;

import java.util.List;

public class CommonCD implements CD {

    private String title = null;
    private String artist = null;
    private List<String> tracks = null;

    public CommonCD() {
    }

    public CommonCD(String title, String artist, List<String> tracks) {
        this.title = title;
        this.artist = artist;
        this.tracks = tracks;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public void setTracks(List<String> tracks) {
        this.tracks = tracks;
    }

    @Override
    public void play() {
        System.out.print("Playing the " + title + " by " + artist);
        for (String track : tracks) {
            System.out.println("Track: " + track);
        }
    }
}