import { defineConfig } from "vitepress";

export const nav = [
  { text: "Головна", link: "/" },
  { text: "Посібник", link: "/guide/introduction/what-is-hangman" },
];

export const sidebar = {
  "/guide/": [
    {
      text: "Введение",
      items: [
        { text: "Що таке Hangman?", link: "/guide/introduction/what-is-hangman" },
        { text: "Дорожня карта проекту", link: "/guide/introduction/roadmap" },
      ],
    },
    {
      text: "Конфигурация",
      items: [
        { text: "Вступ", link: "/guide/installation/" },
        { text: "Налаштування Qt", link: "/guide/installation/qt" },
        { text: "Правила роботи Git", link: "/guide/installation/git" },
        { text: "Правила найменування", link: "/guide/installation/conventional-naming.md" },
        { text: "Стиль коду", link: "/guide/installation/code-style" },
        { text: "Ведення гілок", link: "/guide/installation/conventional-branchs" },
        { text: "Ведення комітів", link: "/guide/installation/conventional-commits" },
      ],
    },
    {
      text: "Розробка",
      items: [
        { text: "Дизайн", link: "/guide/development/design" },
        { text: "Архітектура", link: "/guide/development/architecture" },
        { text: "Технічне завдання", link: "/guide/development/technical-requirements" },
      ],
    },
    {
      text: "Скрам",
      items: [
        { text: "Усі спринти", link: "/guide/iterations/" },
        { text: "Спринт 1", link: "/guide/iterations/sprint-1" },
        { text: "Спринт 2", link: "/guide/iterations/sprint-2" },
      ],
    },
  ],
};

export default defineConfig({
  base: "/university-hangman",
  title: "Шибениця",
  themeConfig: {
    nav,
    sidebar,
    logo: "/assets/favicons/android-chrome-192x192.png",
    socialLinks: [{ icon: "github", link: "https://github.com/dmitrytavern/university-hangman" }],
    footer: {
      message: "Released under the MIT License.",
      copyright: "Copyright © 2023-present Dmitry Tavern",
    },
  },
  head: [
    [
      "link",
      {
        rel: "apple-touch-icon",
        sizes: "180x180",
        href: "/university-hangman/assets/favicons/apple-touch-icon.png",
      },
    ],
    [
      "link",
      {
        rel: "icon",
        type: "image/png",
        sizes: "32x32",
        href: "/university-hangman/assets/favicons/favicon-32x32.png",
      },
    ],
    [
      "link",
      {
        rel: "icon",
        type: "image/png",
        sizes: "16x16",
        href: "/university-hangman/assets/favicons/favicon-16x16.png",
      },
    ],
    [
      "link",
      {
        rel: "manifest",
        href: "/university-hangman/assets/favicons/site.webmanifest",
      },
    ],
    [
      "link",
      {
        rel: "mask-icon",
        href: "/university-hangman/assets/favicons/safari-pinned-tab.svg",
        color: "#4B91F1",
      },
    ],
    [
      "link",
      {
        rel: "shortcut icon",
        href: "/university-hangman/assets/favicons/favicon.ico",
      },
    ],
    ["meta", { name: "msapplication-TileColor", content: "#4B91F1" }],
    [
      "meta",
      {
        name: "msapplication-config",
        content: "/university-hangman/assets/favicons/browserconfig.xml",
      },
    ],
    ["meta", { name: "theme-color", content: "#F3E8DD" }],
  ],
});
