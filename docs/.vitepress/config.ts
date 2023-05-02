import { defineConfig } from "vitepress";

export const nav = [
  { text: "Головна", link: "/" },
  { text: "Посібник", link: "/guide/" },
];

export const sidebar = {
  "/guide/": [],
};

export default defineConfig({
  base: "/university-hangman",
  title: "Шибениця",
  themeConfig: {
    nav,
    sidebar,
    socialLinks: [{ icon: "github", link: "https://github.com/dmitrytavern/university-hangman" }],
  },
});
